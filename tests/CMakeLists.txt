cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(handler_tests)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(handler_tests test_A.cpp test_B.cpp)
target_link_libraries(handler_tests ${GTEST_LIBRARIES})
add_test(NAME handler_tests COMMAND handler_tests)
