from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch_ros.actions import LifecycleNode
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch.actions import LogInfo

import lifecycle_msgs.msg
import os


def generate_launch_description():

    share_dir = get_package_share_directory('config')
    rviz_config_file = os.path.join(share_dir, 'rviz', 'nandhi.rviz')

    Key_listner = Node(
        package='keyboard_ackermann',
        namespace='nandhi',
        executable='keyboard_ackermann',
        name='Key_listner',
        emulate_tty=True,
        output='screen'
    )
    ego_viz_node = Node(
        package='ego_viz',
        namespace='nandhi',
        executable='ego_viz',
        name='ego_viz'
    )
    rviz2_node = Node(package='rviz2',
                      executable='rviz2',
                      name='rviz2',
                      arguments=['-d', rviz_config_file],
                     )
    return LaunchDescription([
        rviz2_node,
        ego_viz_node
    ])
