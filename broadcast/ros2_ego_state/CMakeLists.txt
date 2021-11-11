cmake_minimum_required(VERSION 3.5)
project(ros2_ego_state)

set(target ros2_ego_state)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find packages
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)

# Include our own headers
include_directories(include)

# Create a node
add_executable(${target} src/${target}.cc)

target_link_libraries(${target} imu_sensor)

ament_target_dependencies(${target}
  rclcpp
  sensor_msgs
)

rosidl_target_interfaces(${target} nandhi_msg_types "rosidl_typesupport_cpp")

# Tell downstream packages where to find our headers
ament_export_include_directories(include)
# Tell downstream packages our libraries to link against
ament_export_libraries(my_library)
# Help downstream packages to find transitive dependencies
ament_export_dependencies(
  rclcpp
)
ament_package()