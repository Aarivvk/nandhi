cmake_minimum_required(VERSION 3.16.3)

project(imu_sensor)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(i2c_com REQUIRED)
find_package(nandhi_msg_types REQUIRED)

set(SRCS "src/imu_sensor.cc")
add_library(${PROJECT_NAME} STATIC ${SRCS})
target_include_directories(${PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
  $<INSTALL_INTERFACE:include/>  # <prefix>/include/mylib
)
ament_target_dependencies(${PROJECT_NAME} i2c_com nandhi_msg_types)


# Testing the rpm moduel.
enable_testing()
add_executable(${PROJECT_NAME}_test test/test_imu_sensor.cc)
target_link_libraries(${PROJECT_NAME}_test PRIVATE ${PROJECT_NAME})
add_test(NAME ${PROJECT_NAME}_test COMMAND ${PROJECT_NAME}_test)


# Install section.
install(
  DIRECTORY include/
  DESTINATION include
)

install(TARGETS
    ${PROJECT_NAME}
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin)

# install(TARGETS
#   # Add binary to be installed
#   DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

# Help downstream packages to find transitive dependencies
ament_export_dependencies(
  i2c_com
  nandhi_msg_types
)
ament_export_include_directories(include)
ament_export_libraries(${PROJECT_NAME})

ament_package()