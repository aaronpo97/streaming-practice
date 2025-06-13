cmake_minimum_required(VERSION 3.10)
project(streaming-practice)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/includes)

# Gather all source files
file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES})