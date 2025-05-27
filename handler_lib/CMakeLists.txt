cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STADARD_REQUIRED ON)

project(handler_lib)

add_library(handler_lib STATIC HandlerBase.cpp)
target_include_directories(handler_lib PUBLUC ${CMAKE_CURRENT_SOURCE_DIR})
