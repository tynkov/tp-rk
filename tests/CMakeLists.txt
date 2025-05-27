cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(check)

enable_testing()
include_directories(${CMAKE_SOURCE_DIR}/third-party/gtest handler_lib handler_A handler_B)

add_executable(check test_A.cpp test_B.cpp)
target_include_directories(check PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(check gtest_main gmock_main handler_lib handler_A handler_B)
add_test(NAME check COMMAND check)
