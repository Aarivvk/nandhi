cmake_minimum_required(VERSION 3.16.3)

project(key_to_twist)

# Find packages
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)

set(SRCS "src/key_to_twist.cc")
# add_library(${PROJECT_NAME} STATIC ${SRCS})
add_executable(${PROJECT_NAME} ${SRCS})
target_include_directories(${PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
ament_target_dependencies(${PROJECT_NAME}
  rclcpp
  geometry_msgs
)

# Testing the rpm moduel.
enable_testing()
add_executable(${PROJECT_NAME}_test test/test_key_to_twist.cc)
# target_link_libraries(${PROJECT_NAME}_test PRIVATE )
ament_target_dependencies(${PROJECT_NAME}_test
  rclcpp geometry_msgs
)
add_test(NAME ${PROJECT_NAME}_test COMMAND ${PROJECT_NAME}_test)

install(TARGETS ${PROJECT_NAME}
    DESTINATION lib/${PROJECT_NAME})
ament_package()