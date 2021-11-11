cmake_minimum_required(VERSION 3.16.3)

set(target driver_rpm_single)

find_library(wiringPiLib wiringPi)

set(SRCS "src/rpm_single.cc")
add_library(${target} STATIC ${SRCS})
# add_executable(${target} ${SRCS})
target_include_directories(${target} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
  $<INSTALL_INTERFACE:include/>  # <prefix>/include/mylib
)

target_link_libraries(${target} PRIVATE ${wiringPiLib} pthread rt crypt)


# Testing the rpm moduel.
enable_testing()
add_executable(rpm_single_test test/test_rpm_single.cc)
target_link_libraries(rpm_single_test PRIVATE ${target})
add_test(NAME rpm_single_test COMMAND rpm_test)