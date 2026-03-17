cmake_minimum_required(VERSION 3.10)

project(Microbial_Cultures_SSV_2026_STEP1)

# set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "-Wall")

set(TEST_DIR "${PROJECT_SOURCE_DIR}/Tests")
set(CACHE_DIR "${PROJECT_SOURCE_DIR}/../extlib/Catch/include")

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${CACHE_DIR})
include_directories(${TEST_DIR})

file(
  GLOB
  UTILITY_SOURCES
  "${PROJECT_SOURCE_DIR}/Utility/*.cpp"
  "${PROJECT_SOURCE_DIR}/Utility/*.hpp"
  "${PROJECT_SOURCE_DIR}/JSON/*.cpp"
  "${PROJECT_SOURCE_DIR}/JSON/*.hpp"
  "${PROJECT_SOURCE_DIR}/Random/*.cpp"
  "${PROJECT_SOURCE_DIR}/Random/*.hpp")

file(GLOB CB_SOURCES "${PROJECT_SOURCE_DIR}/Lab/CircularBoundary.cpp" "${PROJECT_SOURCE_DIR}/Lab/CircularBoundary.hpp")

file(
  GLOB
  PROJECT_SOURCES
  "${PROJECT_SOURCE_DIR}/*.cpp"
  "${PROJECT_SOURCE_DIR}/*.hpp"
  "${PROJECT_SOURCE_DIR}/Interface/*.hpp"
  "${PROJECT_SOURCE_DIR}/Lab/*.cpp"
  "${PROJECT_SOURCE_DIR}/Lab/*.hpp"
  ${UTILITY_SOURCES})

file(GLOB SOURCES ${PROJECT_SOURCES})

list(REMOVE_ITEM PROJECT_SOURCES "${PROJECT_SOURCE_DIR}/main.cpp")

file(
  GLOB
  CACHE_SOURCES
  "${CACHE_DIR}/catch.hpp"
  "${TEST_DIR}/UnitTests/CheckUtility.hpp"
  "${TEST_DIR}/UnitTests/CatchTests.cpp"
  # ${SOURCES}
  ${UTILITY_SOURCES})

file(GLOB SOURCES_GFX ${SOURCES})

# Custom target to run the application
add_custom_target(
  application-run
  COMMAND ./application
  DEPENDS application
  WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})

# Helper function for configuring an executable which uses SFML
function(configure_sfml_executable name sfml_include_dirs sfml_cxx_standard sfml_link_libs)
  if(sfml_include_dirs)
    target_include_directories(${name} PRIVATE ${sfml_include_dirs})
  endif()

  if(sfml_cxx_standard)
    set_target_properties(${name} PROPERTIES CXX_STANDARD ${sfml_cxx_standard} CXX_STANDARD_REQUIRED YES)
  endif()

  target_link_libraries(${name} ${sfml_link_libs})
endfunction()

# Function which finds an SFML version
function(find_sfml)
  # Search for SFML versions in this order: >= 3, >= 2.5, >= 2

  set(sfml_link_libs
      ""
      PARENT_SCOPE)
  set(sfml_include_dirs
      ""
      PARENT_SCOPE)
  set(sfml_cxx_standard
      ""
      PARENT_SCOPE)

  set(sfml_found FALSE)

  # Try to find SFML >= 3
  find_package(SFML 3 CONFIG QUIET COMPONENTS Graphics Window System)
  if(NOT SFML_FOUND AND NOT DEFINED SFML_STATIC_LIBRARIES)
    # Some builds install only static libs; try again in that mode
    set(SFML_STATIC_LIBRARIES ON)
    find_package(SFML 3 CONFIG QUIET COMPONENTS Graphics Window System)
    unset(SFML_STATIC_LIBRARIES)
  endif()

  if(SFML_FOUND)
    message(STATUS "Found SFML ${SFML_VERSION_MAJOR}.${SFML_VERSION_MINOR}.${SFML_VERSION_PATCH}")

    # SFML 3 requires C++ 17
    set(sfml_cxx_standard
        17
        PARENT_SCOPE)
    set(sfml_link_libs
        SFML::Graphics SFML::Window SFML::System
        PARENT_SCOPE)
    set(sfml_found TRUE)
  endif()

  if(NOT sfml_found)
    # Try to find SFML >= 2.5
    find_package(SFML 2.5 CONFIG QUIET COMPONENTS graphics window system)

    if(SFML_FOUND)
      message(STATUS "Found SFML ${SFML_VERSION_MAJOR}.${SFML_VERSION_MINOR}.${SFML_VERSION_PATCH}")

      set(sfml_link_libs
          sfml-graphics sfml-window sfml-system
          PARENT_SCOPE)
      set(sfml_found TRUE)
    endif()
  endif()

  if(NOT sfml_found)
    # Try to find SFML >= 2
    set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
    find_package(SFML 2 MODULE QUIET COMPONENTS graphics window system)

    if(SFML_FOUND)
      message(STATUS "SFML_INCLUDE_DIR : ${SFML_INCLUDE_DIR}")
      message(STATUS "SFML_LIBRARIES   : ${SFML_LIBRARIES}")
      message(STATUS "SFML_DEPENDENCIES: ${SFML_DEPENDENCIES}")

      set(sfml_include_dirs
          ${SFML_INCLUDE_DIR}
          PARENT_SCOPE)
      set(sfml_link_libs
          ${SFML_LIBRARIES} ${SFML_DEPENDENCIES}
          PARENT_SCOPE)
      set(sfml_found TRUE)
    endif()
  endif()

  if(NOT sfml_found) # No SFML version found
    message(FATAL_ERROR "SFML NOT FOUND")
  endif()
endfunction()

find_sfml()


# Unit tests

## UNCOMMENT WHEN READY
add_executable(circularBoundaryTest ${TEST_DIR}/UnitTests/CircularBoundaryTest.cpp ${CB_SOURCES} ${CACHE_SOURCES})
configure_sfml_executable(circularBoundaryTest "${sfml_include_dirs}" "${sfml_cxx_standard}" "${sfml_link_libs}")

add_executable(vec2dTest ${TEST_DIR}/UnitTests/Vec2dTest.cpp ${CACHE_SOURCES})
configure_sfml_executable(vec2dTest "${sfml_include_dirs}" "${sfml_cxx_standard}" "${sfml_link_libs}")
