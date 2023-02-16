# Use the latest ROS 2 base image
FROM osrf/ros2:devel

# Install OpenCV
RUN apt-get update && apt-get install -y \
    libopencv-dev \
    python3-opencv \
    && rm -rf /var/lib/apt/lists/*

# Install I2C library support
RUN apt-get update && apt-get install -y \
    i2c-tools \
    libi2c-dev \
    && rm -rf /var/lib/apt/lists/*

# Set the default shell
SHELL ["/bin/bash", "-c"]

# Source the ROS 2 environment
RUN echo "source /opt/ros/eloquent/setup.bash" >> ~/.bashrc

# Create a workspace for your ROS 2 projects
RUN mkdir -p ~/ros2_ws/src

# Set the default working directory
WORKDIR ~/ros2_ws

# # Copy the CI/CD action files
# COPY . .

# # Set the entrypoint to the CI/CD script
# ENTRYPOINT ["./ci_cd_action.sh"]
