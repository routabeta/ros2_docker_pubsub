## About
This is a Dockerized ROS2 Publisher/Subscriber demo project. It repeatedly sends a randomly generated float from publisher to subscriber,  
along with a message count. The goal of the project is to get comfortable writing custom ROS 2 nodes, launch files, and then Dockerizing  
for consistency across environments.

## Features
- ROS 2 Jazzy custom publisher and subscriber nodes
- ROS 2 Jazzy launch file to bring up multiple nodes
- Dockerized environment

## Prerequisites
- [Docker](https://www.docker.com/) installed
- Git installed in order to clone the repo

*You do not need to have ROS 2 installed, as everything runs inside the Docker container*

## Installation
1. Clone the repository:
```bash
git clone https://github.com/routabeta/ros2_docker_pubsub.git
cd ros2_docker_pubsub
```
2. Build the Docker image:
```bash
docker build -t <image_name> .
```
3. Run the container
```bash
docker run --rm --name <container_name> <image_name>
```
The publisher and subscriber nodes will launch automatically, and the container will be autoremoved upon exit with Ctrl-C.
