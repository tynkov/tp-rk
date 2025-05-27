cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STADARD_REQUIRED ON)

project(handler_A)

add_library(handler_A STATIC ConcreteHandlerA.cpp)
target_include_directories(handler_A PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(handler_A handler_lib)

