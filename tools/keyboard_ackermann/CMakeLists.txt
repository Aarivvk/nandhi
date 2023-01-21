cmake_minimum_required(VERSION 3.16.3)

project(keyboard_ackermann)

# Find packages
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(nandhi_msg_types REQUIRED)

set(SRCS "src/keyboard_ackermann.cc")
# add_library(${PROJECT_NAME} STATIC ${SRCS})
add_executable(${PROJECT_NAME} ${SRCS})
target_include_directories(${PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
ament_target_dependencies(${PROJECT_NAME}
  rclcpp
  nandhi_msg_types
)

# Testing the rpm moduel.
enable_testing()
add_executable(${PROJECT_NAME}_test test/test_keyboard_ackermann.cc)
# target_link_libraries(${PROJECT_NAME}_test PRIVATE )
ament_target_dependencies(${PROJECT_NAME}_test
  rclcpp nandhi_msg_types
)
add_test(NAME ${PROJECT_NAME}_test COMMAND ${PROJECT_NAME}_test)

ament_package()