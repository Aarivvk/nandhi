# Use the latest ROS 2 base image
FROM ubuntu:22.04


RUN apt-get update && apt-get upgrade -y

# Install OpenCV
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends\
    libopencv-dev \
    python3-opencv

# Install I2C library support
RUN apt-get install -y \
    i2c-tools \
    libi2c-dev

# Install ROS2 Rolling...
RUN apt-get install -y locales
RUN locale-gen en_US en_US.UTF-8
RUN update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
ENV LANG=en_US.UTF-8

RUN apt-get install -y curl ca-certificates \
    && curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key \
    -o /usr/share/keyrings/ros-archive-keyring.gpg

RUN echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] \
    http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | \
    tee /etc/apt/sources.list.d/ros2.list > /dev/null

RUN apt-get update && apt-get upgrade -y

RUN apt install -y ros-rolling-ros-base ros-dev-tools

# Set the default shell
SHELL ["/bin/bash", "-c"]

# Source the ROS 2 environment
RUN echo "source /opt/ros/rolling/setup.bash" >> ~/.bashrc

# Create a workspace for your ROS 2 projects
RUN mkdir -p /ros2_ws/src

# Set the default working directory
WORKDIR /ros2_ws

# # Copy the CI/CD action files
COPY . .


RUN rm -rf /var/lib/apt/lists/*

# Set the entrypoint to the CI/CD script
ENTRYPOINT ["./ci_cd_action.sh"]