from ament_index_python import get_package_share_directory
from launch import LaunchDescription
from launch_ros.parameter_descriptions import ParameterValue
from launch.substitutions import Command
from launch_ros.actions import Node
from os import path
from ament_index_python.packages import get_package_share_path
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch.actions import IncludeLaunchDescription


def generate_launch_description():
    share_dir = get_package_share_directory('config')
    urdf_path = path.join(share_dir, 'urdf', 'nandhi.urdf.xacro')
    robot_description = ParameterValue(Command(['xacro ', urdf_path]), value_type=str)

    robot_state_publisher_node = Node(
        package='robot_state_publisher',
        namespace='/',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        parameters=[{'robot_description': robot_description}],
        emulate_tty=True,
        output='screen'
    )

    joint_state_publisher = Node(
        package='joint_state_publisher_gui',
        namespace='/',
        executable='joint_state_publisher_gui',
        name='joint_state_publisher',
        emulate_tty=True,
        output='screen'
    )
    
    share_dir = get_package_share_directory('config')
    rviz_config_file = path.join(share_dir, 'rviz', 'sim.rviz')
    rviz2_node = Node(package='rviz2',
                      executable='rviz2',
                      namespace='/',
                      name='rviz2',
                      arguments=['-d', rviz_config_file],
                      )


    # Setup to launch the simulator and Gazebo world
    pkg_ros_gz_sim = get_package_share_directory('ros_gz_sim')
    gz_sim = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            path.join(pkg_ros_gz_sim, 'launch', 'gz_sim.launch.py')),
    )

    # Bridge ROS topics and Gazebo messages for establishing communication
    bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        parameters=[{
            'config_file': path.join(share_dir, 'gz', 'bridge.yaml'),
            'qos_overrides./tf_static.publisher.durability': 'transient_local',
        }],
        output='screen'
    )

    return LaunchDescription([
        robot_state_publisher_node,
        joint_state_publisher,
        rviz2_node,
        gz_sim,
        bridge
    ])
