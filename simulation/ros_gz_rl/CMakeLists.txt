cmake_minimum_required(VERSION 3.10.2 FATAL_ERROR)

project(ros_gz_rl)


# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

find_package(ament_cmake REQUIRED)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
  
  find_package(gz-sim8 REQUIRED)
  set(GZ_SIM_VER ${gz-sim8_VERSION_MAJOR})
  find_package(gz-transport13 QUIET REQUIRED OPTIONAL_COMPONENTS log)
  set(GZ_TRANSPORT_VER ${gz-transport13_VERSION_MAJOR})

  # Create a node
  add_executable(${PROJECT_NAME} src/${PROJECT_NAME}.cc)
  # Include our own headers
  target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
  
  target_link_libraries(${PROJECT_NAME}
    gz-sim${GZ_SIM_VER}::gz-sim${GZ_SIM_VER} gz-transport${GZ_TRANSPORT_VER}::core)

endif()

install(TARGETS ${PROJECT_NAME} DESTINATION lib/${PROJECT_NAME})
    
ament_package()