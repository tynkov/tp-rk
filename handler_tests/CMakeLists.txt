cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(handler_tests)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} handler_lib handler_A handler_B)

add_executable(handler_tests test_A.cpp test_B.cpp)
target_include_directories(handler_tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(handler_tests ${GTEST_LIBRARIES} handler_lib handler_A handler_B)
add_test(NAME handler_tests COMMAND handler_tests)
