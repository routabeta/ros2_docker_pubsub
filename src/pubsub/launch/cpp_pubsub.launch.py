from launch import LaunchDescription 
from launch_ros.actions import Node

def generate_launch_description():

    cpp_pub_node = Node(
        name='Publisher',
        package='pubsub',
        executable='cpp_pub',
        output='screen'
    )

    cpp_sub_node = Node(
        name='Subscriber',
        package='pubsub',
        executable='cpp_sub',
        output='screen'
    )

    return LaunchDescription([
        cpp_pub_node,
        cpp_sub_node
    ])