cmake_minimum_required(VERSION 3.16.3)

project(vehicle_control_system)

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
find_package(i2c_pwm_pca9685 REQUIRED)
find_package(geometry_msgs REQUIRED)

set(SRCS "src/vcs.cc")
add_executable(${PROJECT_NAME} ${SRCS})
target_include_directories(${PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
ament_target_dependencies(${PROJECT_NAME}
  rclcpp
  i2c_pwm_pca9685
  i2c_com
  geometry_msgs
)

# Testing the PCA9685 moduel.
enable_testing()
add_executable(${PROJECT_NAME}_test test/test_vcs.cc)
ament_target_dependencies(${PROJECT_NAME}_test 
  rclcpp
  i2c_pwm_pca9685
  i2c_com
  geometry_msgs
)
add_test(NAME ${PROJECT_NAME}_test COMMAND ${PROJECT_NAME}_test)


install(
  TARGETS ${PROJECT_NAME}
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()