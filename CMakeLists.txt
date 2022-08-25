cmake_minimum_required(VERSION 3.12)

project (cnc
    VERSION 0.1.0
    DESCRIPTION "Lightweight and highly customizable C++ command line interface library"
    LANGUAGES CXX)

if (NOT USE_AS_SUBPROJECT)
    # Variable Toggles
    set(NO_COLOR OFF CACHE INTERNAL "Toggles colored output errors")
    set(BUILD_DOC ON CACHE INTERNAL "Build documentation")
    set(ENABLE_LOGGING OFF CACHE INTERNAL "View the logging statements/debug info")
    set(LOG_LEVEL 0 CACHE INTERNAL "Enable only specific log levels")
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

if (NO_COLOR)
    # Don't use colored output
else()
    # Include colored output by default
    include(Color)
endif()

# Include dependencies
# CMake modules
include(Library)

include(spdlog)
include(tomlplusplus)
include(utility)

# Includes directory
set(INCLUDES_DIR ${PROJECT_SOURCE_DIR}/include)
set(COMMAND_DIR ${INCLUDES_DIR}/command)

# Add subdirectories
add_subdirectory(src)

if (BUILD_TESTING AND NOT USE_AS_SUBPROJECT)
    include(doctest)
    include(MakeTests)
    include(CTest)
    add_subdirectory(tests)
endif()


if (NOT USE_AS_SUBPROJECT)
    # Package for debian
    include(Debian)
endif()
