ROS2_NAME="$1"

# https://docs.ros.org/en/humble/Installation/Alternatives/Ubuntu-Development-Setup.html
# Add the ROS 2 GPG key with apt.
sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg

# Add the repository to your sources list.
echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null

# Install common packages
sudo apt update && sudo apt install -y \
  python3-flake8-docstrings \
  python3-pip \
  python3-pytest-cov \
  ros-dev-tools

# Initialize rosdep
sudo rosdep init
rosdep update
# Install ROS 2 workspace dependencies
rosdep install -y --rosdistro "$ROS2_NAME" --from-paths .
