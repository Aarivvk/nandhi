import os
from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():

    share_dir = get_package_share_directory('config')
    rviz_config_file = os.path.join(share_dir, 'rviz', 'nandhi.rviz')

    ego_viz_node = Node(
        package='ego_viz',
        namespace='vizualisation',
        executable='ego_viz',
        name='ego_viz'
    )
    rviz2_node = Node(package='rviz2',
                      executable='rviz2',
                      namespace='vizualisation',
                      name='rviz2',
                      arguments=['-d', rviz_config_file],
                      )
    return LaunchDescription([
        ego_viz_node,
        rviz2_node
    ])
