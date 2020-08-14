cmake_minimum_required(VERSION 3.10)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Include header directories from the main project.
include_directories(${PROJECT_SOURCE_DIR}/../header)
message(${PROJECT_SOURCE_DIR})

# Link TaskManager with what we want to test and the GTest and pthread library
add_executable(
    TestTaskManager 
    main.cpp
    testusers.cpp
    ../src/users.cpp
    ../src/model.cpp
    )
target_link_libraries(TestTaskManager ${GTEST_LIBRARIES} pthread)