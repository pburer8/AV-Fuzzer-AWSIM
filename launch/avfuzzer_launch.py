from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='egoposesub',
            namespace='egoposesub',
            executable='ego_pose',
            name='ego_pose_sub'
        ),
        Node(
            package='nearestlane',
            namespace='nearestlane',
            executable='nearest_lane',
            name='map'
        )
    ])