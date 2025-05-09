#!/bin/bash
set -e

source /opt/ros/$ROS_DISTRO/setup.bash
source /docker_pubsub_project/install/setup.bash

exec ros2 launch pubsub cpp_pubsub.launch.py
