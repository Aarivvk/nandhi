from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import LifecycleNode
from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():

    share_dir = get_package_share_directory('config')
    parameter_file = LaunchConfiguration('params_file')

    params_declare = DeclareLaunchArgument('params_file',
                                           default_value=os.path.join(
                                               share_dir, 'lidar/params', 'ydlidar.yaml'),
                                           description='FPath to the ROS2 parameters file to use.')

    lidar_driver_node = LifecycleNode(package='ydlidar_ros2_driver',
                                      executable='ydlidar_ros2_driver_node',
                                      name='ydlidar_ros2_driver_node',
                                      output='screen',
                                      emulate_tty=True,
                                      parameters=[parameter_file],
                                      namespace='nandhi',
                                      )

    tf2_node = Node(package='tf2_ros',
                    executable='static_transform_publisher',
                    name='static_tf_pub_laser',
                    arguments=['0', '0', '0.02', '0', '0',
                               '0', '1', 'base_link', 'nandhi_frame'],
                    )

    vcs_node = Node(
        package='vehicle_control_system',
        namespace='nandhi',
        executable='vehicle_control_system',
        name='VCS',
        output='screen',
        emulate_tty=True
    )

    vehicle_state_node = Node(
        package='ego_state',
        namespace='nandhi',
        executable='ego_state',
        name='VS',
        output='screen',
        emulate_tty=True
    )
    return LaunchDescription([
        params_declare,
        lidar_driver_node,
        tf2_node,
        vcs_node,
        vehicle_state_node
    ])
