cmake_minimum_required(VERSION 3.15)

project(voidproxy_core)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Position independent code for shared library
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Include headers
include_directories(${CMAKE_SOURCE_DIR}/include)

# Collect all cpp source files
file(GLOB_RECURSE SOURCES
    ${CMAKE_SOURCE_DIR}/src/*.cpp
)

# Build shared library
add_library(voidproxy_core SHARED ${SOURCES})

# Output directory
set_target_properties(voidproxy_core PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)