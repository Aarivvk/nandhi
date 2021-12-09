cmake_minimum_required(VERSION 3.16.3)

set(target driver_l298n_dc)

find_library(wiringPiLib wiringPi)

set(SRCS "src/l298n_dc.cc")
add_library(${target} STATIC ${SRCS})
# add_executable(${target} ${SRCS})
target_include_directories(${target} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
  $<INSTALL_INTERFACE:include/>  # <prefix>/include/mylib
)

target_link_libraries(${target} PRIVATE ${wiringPiLib} pthread rt crypt)


# Testing the rpm moduel.
enable_testing()
add_executable(${target}_test test/test_l298n_dc.cc)
target_link_libraries(${target}_test PRIVATE ${target})
add_test(NAME ${target}_test COMMAND ${target}_test )