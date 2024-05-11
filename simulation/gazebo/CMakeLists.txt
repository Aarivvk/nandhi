cmake_minimum_required(VERSION 3.5)

# Following directive defines the project name.
project(gazebo)

find_package(ament_cmake REQUIRED)

# Following 'install' directive ensures that the 'worlds' subfolder
# will be copied to the 'share/ros_gz_example_gazebo/worlds'
# subfolder of the installation directory.
install(
  DIRECTORY worlds/
  DESTINATION share/${PROJECT_NAME}/worlds
)


# Following directive configures ament based on the previous directives, and should
# typically be the last directive in the CMakeLists.txt file.
ament_package()