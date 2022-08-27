cmake_minimum_required(VERSION 3.16.3)

set(target i2c_pwm_pca9685)

set(SRCS "src/i2c_pwm.cc")
add_library(${target} STATIC ${SRCS})
target_include_directories(${target} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
  $<INSTALL_INTERFACE:include/>  # <prefix>/include/mylib
)

target_link_libraries(${target} PUBLIC driver_i2c_com)


# Testing the PCA9685 moduel.
enable_testing()
add_executable(${target}_test test/test_PCA9685.cc)
target_link_libraries(${target}_test PRIVATE ${target})
add_test(NAME ${target}_test COMMAND ${target}_test)
