cmake_minimum_required(VERSION 3.16.3)

set(target imu_sensor)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

set(SRCS "src/imu_sensor.cc")
add_library(${target} STATIC ${SRCS})
target_include_directories(${target} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
  $<INSTALL_INTERFACE:include/>  # <prefix>/include/mylib
)

target_link_libraries(${target} driver_i2c_com)

rosidl_target_interfaces(${target} nandhi_msg_types "rosidl_typesupport_cpp")


# Testing the rpm moduel.
enable_testing()
add_executable(${target}_test test/test_imu_sensor.cc)
target_link_libraries(${target}_test PRIVATE ${target})
add_test(NAME ${target}_test COMMAND ${target}_test)