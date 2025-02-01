import rclpy
import signal
from rclpy.node import Node
from nandhi_msg_types.srv import GetObservations

class RosSimClient(Node):
    def __init__(self):
        rclpy.init(args=None)
        super().__init__('ros_sim_client')
        self.client = self.create_client(GetObservations, '/ros_gz_rl')
        self.terminate = False
        signal.signal(signal.SIGINT, self.signal_handler)

    def __wait_for_service(self):
        while not self.client.wait_for_service(timeout_sec=1.0):
            if not self.is_ros_okay():
                self.get_logger().info('Exiting...')
                return False
            self.get_logger().info('service not available, waiting again...')
        return True

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
        self.destroy_node()
        rclpy.shutdown()
