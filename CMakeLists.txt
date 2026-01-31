cmake_minimum_required(VERSION 3.10)
project(MyZip VERSION 1.0 LANGUAGES C)

# Set C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Configure output directories for binaries and libs
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Include the 'include' directory for headers
include_directories(inc)

# Testing
include(CTest)
enable_testing()

# Add the source directory
add_subdirectory(src)
add_subdirectory(test)