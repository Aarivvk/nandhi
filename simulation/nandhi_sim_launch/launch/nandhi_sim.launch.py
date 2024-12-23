import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.actions import IncludeLaunchDescription
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration

from launch_ros.actions import Node


def generate_launch_description():
    # Configure ROS nodes for launch

    # Setup project paths
    pkg_project_bringup = get_package_share_directory('nandhi_sim_launch')
    pkg_project_gazebo = get_package_share_directory('gazebo')
    pkg_project_description = get_package_share_directory('nandhi_description')
    pkg_ros_gz_sim = get_package_share_directory('ros_gz_sim')

    # Setup to launch the simulator and Gazebo world
    gz_sim = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg_ros_gz_sim, 'launch', 'gz_sim.launch.py')),
        # TODO : Remove the -r as not to start the simulator as it will be started by ros_gz_rl
        launch_arguments={'gz_args': '-s -r -v 3 '+os.path.join(
            pkg_project_gazebo,
            'worlds',
            'industrial-warehouse.sdf'
        )}.items(),
    )

    # Load the SDF file from "description" package
    sdf_file  =  os.path.join(pkg_project_description, 'models', 'nandhi', 'model.sdf')
    with open(sdf_file, 'r') as f:
        robot_description = f.read()
    # Takes the description and joint angles as inputs and publishes the 3D poses of the robot links
    robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        output='both',
        parameters=[
            {'use_sim_time': True},
            {'robot_description': robot_description},
        ]
    )

    # Visualize in RViz
    rviz2 = Node(
       package='rviz2',
       executable='rviz2',
       arguments=['-d', os.path.join(pkg_project_bringup, 'config', 'nandhi_sim.rviz')],
       parameters=[
            {'use_sim_time': True},
        ],
       condition=IfCondition(LaunchConfiguration('rviz'))
    )

    # Bridge ROS topics and Gazebo messages for establishing communication
    ros_gz_bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        parameters=[{
            'config_file': os.path.join(pkg_project_bringup, 'config', 'ros_gz_nandhi_bridge.yaml'),
            'qos_overrides./tf_static.publisher.durability': 'transient_local',
        }],
        output='screen'
    )

    spawn = Node(package='ros_gz_sim', executable='create',
                parameters=[{
                'world': 'indoor',
                'name': 'nandhi',
                'x': 0.0,
                'z': 0.0,
                'Y': 0.0,
                'topic': '/robot_description'}],
                output='screen')

    ros_gz_rl = Node(package='ros_gz_rl',
                       executable='ros_gz_rl',
                       output='screen')

    return LaunchDescription([
        DeclareLaunchArgument('rviz', default_value='false',
                             description='Open RViz.'),
        gz_sim,
        ros_gz_bridge,
        # spawn
        ros_gz_rl,
        robot_state_publisher,
        rviz2
    ])
