cmake_minimum_required(VERSION 3.10)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link TaskManager with what we want to test and the GTest and pthread library
add_executable(
    TestTaskManager 
    main.cpp
    )
target_link_libraries(TestTaskManager ${GTEST_LIBRARIES} pthread)