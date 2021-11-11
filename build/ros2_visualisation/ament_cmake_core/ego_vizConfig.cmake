# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_ego_viz_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED ego_viz_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(ego_viz_FOUND FALSE)
  elseif(NOT ego_viz_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(ego_viz_FOUND FALSE)
  endif()
  return()
endif()
set(_ego_viz_CONFIG_INCLUDED TRUE)

# output package information
if(NOT ego_viz_FIND_QUIETLY)
  message(STATUS "Found ego_viz: 0.0.1 (${ego_viz_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'ego_viz' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${ego_viz_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(ego_viz_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "ament_cmake_export_include_directories-extras.cmake;ament_cmake_export_libraries-extras.cmake;ament_cmake_export_dependencies-extras.cmake")
foreach(_extra ${_extras})
  include("${ego_viz_DIR}/${_extra}")
endforeach()
