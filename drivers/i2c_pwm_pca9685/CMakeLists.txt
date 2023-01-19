cmake_minimum_required(VERSION 3.16.3)

project(i2c_pwm_pca9685)

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(i2c_com REQUIRED)

set(SRCS "src/i2c_pwm.cc")
add_library(${PROJECT_NAME} STATIC ${SRCS})
# target_link_libraries(${PROJECT_NAME} PUBLIC driver_i2c_com)
ament_target_dependencies(${PROJECT_NAME} i2c_com)
target_include_directories(${PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
  $<INSTALL_INTERFACE:include/>  # <prefix>/include/mylib
)


# Testing the PCA9685 moduel.
enable_testing()
add_executable(${PROJECT_NAME}_test test/test_PCA9685.cc)
target_link_libraries(${PROJECT_NAME}_test PRIVATE ${PROJECT_NAME})
add_test(NAME ${PROJECT_NAME}_test COMMAND ${PROJECT_NAME}_test)

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

ament_package()