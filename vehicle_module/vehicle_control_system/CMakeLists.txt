cmake_minimum_required(VERSION 3.16.3)

set(target vehicle_control_system)

set(SRCS "src/vcs.cc")
add_library(${target} STATIC ${SRCS})
target_include_directories(${target} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
  $<INSTALL_INTERFACE:include/>  # <prefix>/include/mylib
)

target_link_libraries(${target} PUBLIC i2c_pwm_pca9685)


# Testing the PCA9685 moduel.
enable_testing()
add_executable(${target}_test test/test_vcs.cc)
target_link_libraries(${target}_test PRIVATE ${target} pthread)
add_test(NAME ${target}_test COMMAND ${target}_test)
