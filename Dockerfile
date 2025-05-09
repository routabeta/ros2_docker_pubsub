FROM ros:jazzy

# Set up env variables
ENV ROS_DISTRO=jazzy
ENV DEBIAN_FRONTEND=noninteractive

# Install colcon to build
RUN apt-get update && apt-get install -y \
	python3-colcon-common-extensions \
	build-essential \
	&& rm -rf /var/lib/apt/lists/*

# Navigate to ws root (which is also Docker build root) and copy files
WORKDIR /docker_pubsub_project
COPY . .
RUN ls -a | echo

# Build
RUN rm -rf build/ install/ log/ \
	&& bash -c "source /opt/ros/${ROS_DISTRO}/setup.bash && colcon build"

COPY entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh
ENTRYPOINT ["/entrypoint.sh"]
CMD ["bash"]


