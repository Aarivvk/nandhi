cmake_minimum_required(VERSION 3.16.3)

project(config)

# Find packages
find_package(ament_cmake REQUIRED)

add_library(${PROJECT_NAME} INTERFACE)

install(DIRECTORY lidar rviz urdf
    DESTINATION share/${PROJECT_NAME})

ament_package()