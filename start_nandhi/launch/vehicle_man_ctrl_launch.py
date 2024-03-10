from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    Key_listner = Node(
        package='keyboard_ackermann',
        namespace='nandhi',
        executable='keyboard_ackermann',
        name='Key_listner',
        emulate_tty=True,
        output='screen'
    )
    return LaunchDescription([
        Key_listner
    ])
