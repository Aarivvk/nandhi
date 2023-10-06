# Use the latest ROS 2 base image
FROM nvcr.io/nvidia/pytorch:23.09-py3


# Install OpenCV && I2C library support
RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
    libopencv-dev \
    python3-opencv \
    i2c-tools \
    libi2c-dev

# Install ROS2 Rolling...
RUN apt-get install -y locales && locale-gen en_US en_US.UTF-8 && \
    update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8

ENV LANG=en_US.UTF-8

RUN apt-get install -y curl ca-certificates \
    && curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key \
    -o /usr/share/keyrings/ros-archive-keyring.gpg && \
    echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] \
    http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | \
    tee /etc/apt/sources.list.d/ros2.list > /dev/null && \
    apt-get update && apt-get upgrade -y && apt-get install -y ros-rolling-ros-base ros-dev-tools

# Set the default shell
SHELL ["/bin/bash", "-c"]

# Source the ROS 2 environment
RUN echo "source /opt/ros/rolling/setup.bash" >> ~/.bashrc && rm -rf /var/lib/apt/lists/*
