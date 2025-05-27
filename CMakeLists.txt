cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STADARD_REQUIRED ON)

option(BUILD_TESTS "Build tests" OFF)

project(ChainOfResponsibility)

add_subdirectory(handler_lib)
add_subdirectory(handler_A)
add_subdirectory(handler_B)

add_executable(ChainOfResponsibility main.cpp)
target_link_libraries(ChainOfResponsibility handler_A handler_B)

if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(third-party/gtest)
  add_executable(check tests/test.cpp)
  target_link_libraries(check gtest_main handler_A handler_B)
  add_test(NAME check COMMAND check)
endif()
