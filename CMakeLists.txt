cmake_minimum_required (VERSION 2.6)
project (Poles)

# version number
set (Poles_VERSION_MAJOR 0)
set (Poles_VERSION_MINOR 1)

# Specify include paths
set (PROJECT_SOURCE_DIR "${PROJECT_BINARY_DIR}/src")
set (Poles_SOURCE_DIR "${PROJECT_BINARY_DIR}/src")

# Specify build paths
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# add binary tree to search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_SOURCE_DIR}")

# Add executable
add_executable(Poles "${PROJECT_SOURCE_DIR}/main.cpp")
