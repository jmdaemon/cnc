cmake_minimum_required(VERSION 3.12)

project (cnc
    VERSION 0.1.0
    DESCRIPTION "Lightweight and highly customizable C++ command line interface library"
    LANGUAGES CXX
    )

# Default the standarad to c++17
if (NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 17) 
    set(CSTANDARD "cxx_std_${CMAKE_CXX_STANDARD}")
endif()

set_property(GLOBAL PROPERTY USE_FOLDERS ON) 

# Use colored output
if (NOT COLOR)
    # Don't use colored output
else()
    # Include colored output by default
    include(Color)
endif()

# Require out-of-source builds
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")
    message(FATAL_ERROR "You cannot build in a source directory (or any directory with "
                        "CMakeLists.txt file). Please make a build subdirectory. Feel free to "
                        "remove CMakeCache.txt and CMakeFiles.")
endif()

# Include CMake modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMake/modules/" "${PROJECT_SOURCE_DIR}/cmake")

# Single source project versions
configure_file (
  "${PROJECT_SOURCE_DIR}/include/Version.h.in"
  "${PROJECT_BINARY_DIR}/include/Version.h"
)

# Include dependencies
include(FetchContent)
include(Library)
include(Utilities)
include(spdlog)
include(tomlplusplus)
include(doctest)
include(utility)

# Includes directory
set(INCLUDES_DIR "${PROJECT_SOURCE_DIR}/include")
set(COMMAND_DIR "${INCLUDES_DIR}/command")

# Add subdirectories
add_subdirectory(src)

if(BUILD_TESTING)
  add_subdirectory(tests)
endif()

# Package for debian
include(Debian)
