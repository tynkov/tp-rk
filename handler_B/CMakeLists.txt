cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STADARD_REQUIRED ON)

project(handler_B)

add_library(handler_B STATIC ConcreteHandlerB.cpp)
target_include_directories(handler_B PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(handler_B handler_lib)
