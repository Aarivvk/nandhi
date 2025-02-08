import rclpy
import signal
from sensor_msgs.msg import Image
from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import Twist
from cv_bridge import CvBridge
import cv2
import numpy as np
from rclpy.node import Node
from nandhi_msg_types.srv import GetObservations
from rl.nandhi_control_center import PygameOpenCVCarControl

class RosSimClient(Node):
    def __init__(self):
        rclpy.init(args=None)
        super().__init__('ros_sim_client')
        self.client = self.create_client(GetObservations, '/ros_gz_rl')
        self.cam_sub = self.create_subscription(Image, '/camera', self.__camera_callback, 10)
        self.cam_sub  # prevent unused variable warning
        self.laser_2d_sub = self.create_subscription(LaserScan, '/laser_scan', self.__laser_callback, 10)
        self.laser_2d_sub  # prevent unused variable warning
        self.twist_pub = self.create_publisher(Twist, '/nandhi/cmd_vel', 10)

        self.control_center = PygameOpenCVCarControl()

        self.bridge = CvBridge()
        self.terminate = False
        signal.signal(signal.SIGINT, self.signal_handler)

        self.camera_image = None
        self.laser_scan = None

    def __camera_callback(self, msg):
        # Convert ROS Image message to OpenCV format
        self.camera_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')

    def __laser_callback(self, msg):
        self.laser_scan = msg

    def __project_laserscan_to_image(self, scan: LaserScan, image: np.ndarray, cam_fov: float = np.deg2rad(90), lidar_to_cam_transform=None):
        """
        Projects LaserScan points onto an Image while considering the camera's field of view and sensor alignment.

        :param scan: sensor_msgs/LaserScan message.
        :param image: OpenCV image (numpy.ndarray).
        :param cam_fov: Camera horizontal field of view in radians.
        :param lidar_to_cam_transform: 4x4 transformation matrix from LiDAR frame to camera frame.
        :return: OpenCV image with projected points.
        """

        cam_height, cam_width = image.shape[:2]

        if lidar_to_cam_transform is None:
            lidar_to_cam_transform = np.eye(4)  # Default identity transformation matrix

        # Extract scan parameters
        angles = np.linspace(scan.angle_min, scan.angle_max, len(scan.ranges))
        ranges = np.array(scan.ranges)

        # Filter valid points
        valid_mask = (ranges > scan.range_min) & (ranges < scan.range_max)
        angles = angles[valid_mask]
        ranges = ranges[valid_mask]

        # Convert polar to Cartesian coordinates in LiDAR frame
        points_lidar = np.vstack((ranges * np.cos(angles), 
                                ranges * np.sin(angles),
                                np.zeros_like(ranges),
                                np.ones_like(ranges)))
        
        # Transform points to camera frame
        points_cam = lidar_to_cam_transform @ points_lidar

        # Extract only points in front of the camera
        valid_cam_mask = points_cam[2, :] > 0  # Z > 0 (in front of camera)
        points_cam = points_cam[:, valid_cam_mask]

        # Project points to image plane
        focal_length = cam_width / (2 * np.tan(cam_fov / 2))

        u = (focal_length * points_cam[0, :] / points_cam[2, :]) + (cam_width / 2)
        v = (focal_length * points_cam[1, :] / points_cam[2, :]) + (cam_height / 2)

        # Filter points within image bounds
        valid_proj_mask = (u >= 0) & (u < cam_width) & (v >= 0) & (v < cam_height)
        u, v = u[valid_proj_mask].astype(int), v[valid_proj_mask].astype(int)

        # Draw points on image
        for x, y in zip(u, v):
            cv2.circle(image, (x, y), 2, (0, 0, 255), -1)

        return image

    def __wait_for_service(self):
        while not self.client.wait_for_service(timeout_sec=1.0):
            if not self.is_ros_okay():
                self.get_logger().info('Exiting...')
                return False
            self.get_logger().info('service not available, waiting again...')
        return True

    def display(self):
        if self.laser_scan is not None and self.camera_image is not None:
            final_image = self.__project_laserscan_to_image(self.laser_scan, self.camera_image)
            twist = self.control_center.update(final_image)
            # Ensure twist message fields are floats
            twist.linear.x = float(twist.linear.x)
            twist.linear.y = float(twist.linear.y)
            twist.linear.z = float(twist.linear.z)
            twist.angular.x = float(twist.angular.x)
            twist.angular.y = float(twist.angular.y)
            twist.angular.z = float(twist.angular.z)
            self.twist_pub.publish(twist)
        else:
            self.get_logger().warn("Laser scan or camera image is not available.")

    def request(self, reset=False, step=False, multi_step=0):
        try:
            self.__wait_for_service()
            request = GetObservations.Request()
            request.reset = reset
            request.step = step
            request.multi_step = multi_step
            future = self.client.call_async(request)
            # block the thread until the future is complete
            ret = rclpy.spin_until_future_complete(self, future, timeout_sec=1.0)
            if ret:
                self.get_logger().error('service call failed')
                return None, None
            response = future.result()
            if response is None:
                self.get_logger().error('service call failed')
                return None, None
            else:
                return response.crash, response.t_distance
        except (KeyboardInterrupt, ExternalShutdownException):
            self.get_logger().info('Exiting...')
            self.terminate = True
            return None, None

    def signal_handler(self, sig, frame):
        self.terminate = True
        self.get_logger().info("User termination signal received...")

    def is_ros_okay(self):
        return rclpy.ok() and not self.terminate

    def __del__(self):
        self.control_center.stop()
        self.destroy_node()
        rclpy.shutdown()
        cv2.destroyAllWindows()
