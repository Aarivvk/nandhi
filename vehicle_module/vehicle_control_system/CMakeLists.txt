cmake_minimum_required(VERSION 3.16.3)

set(target vehicle_control_system)

# Find packages
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(i2c_pwm_pca9685 REQUIRED)

set(SRCS "src/vcs.cc")
add_executable(${target} ${SRCS})
target_include_directories(${target} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
  $<INSTALL_INTERFACE:include/>  # <prefix>/include/mylib
)

ament_target_dependencies(${target}
  rclcpp
  # i2c_pwm_pca9685
)
rosidl_target_interfaces(${target} nandhi_msg_types "rosidl_typesupport_cpp")
# target_link_libraries(${target} PUBLIC i2c_pwm_pca9685)

# Testing the PCA9685 moduel.
enable_testing()
add_executable(${target}_test test/test_vcs.cc)
target_link_libraries(${target}_test PRIVATE pthread i2c_pwm_pca9685)
add_test(NAME ${target}_test COMMAND ${target}_test)
