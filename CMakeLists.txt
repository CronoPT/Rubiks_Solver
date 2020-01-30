cmake_minimum_required(VERSION 3.13)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(run_tests tests/tests.cpp)
target_link_libraries(run_tests ${GTEST_LIBRARIES} pthread)