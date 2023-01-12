cmake_minimum_required(VERSION 3.16.3)

set(target keyboard_ackermann)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

set(SRCS "src/keyboard_ackermann.cc")
add_library(${target} STATIC ${SRCS})
target_include_directories(${target} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
  $<INSTALL_INTERFACE:include/>  # <prefix>/include/mylib
)

# target_link_libraries(${target} PRIVATE nandhi_msg_types)

rosidl_target_interfaces(${target} nandhi_msg_types "rosidl_typesupport_cpp")

# Testing the rpm moduel.
enable_testing()
add_executable(${target}_test test/test_keyboard_ackermann.cc)
target_link_libraries(${target}_test PRIVATE ${target})
ament_target_dependencies(${target} rclcpp std_msgs)
add_test(NAME ${target}_test COMMAND ${target}_test)
