cmake_minimum_required(VERSION 3.5)
project(ego_viz)

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find packages
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(visualization_msgs REQUIRED)
find_package(nandhi_msg_types REQUIRED)

# Include our own headers
include_directories(include)

# Create a node
add_executable(${PROJECT_NAME} src/${PROJECT_NAME}.cc)

ament_target_dependencies(${PROJECT_NAME}
  rclcpp
  visualization_msgs
  nandhi_msg_types
)

ament_package()