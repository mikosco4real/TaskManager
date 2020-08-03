cmake_minimum_required(VERSION 3.10)

# Set Variables
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

# Give the Project name which is also the output file name
project(TaskManager)

# Include Subdirectories and includes directories

include_directories(${PROJECT_SOURCE_DIR}/header)
# add_subdirectory(${PROJECT_SOURCE_DIR}/src)
 
# Add the Executable Files
add_executable(
    TaskManager
    src/main.cpp
    )
