cmake_minimum_required(VERSION 3.16.3)

set(target vehicle_state_estimator)

set(SRCS "src/vehicle_state_estimator.cc")
add_library(${target} STATIC ${SRCS})
target_include_directories(${target} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
  $<INSTALL_INTERFACE:include/>  # <prefix>/include/mylib
)

target_link_libraries(${target} imu_sensor)


# Testing the rpm moduel.
enable_testing()
add_executable(${target}_test test/test_vehicle_state_estimator.cc)
target_link_libraries(${target}_test PRIVATE ${target})
add_test(NAME ${target}_test COMMAND ${target}_test)