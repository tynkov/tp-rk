cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STADARD_REQUIRED ON)

project(ChainOfResponsibility)

add_executable(ChainOfResponsibility main.cpp)
target_link_libraries(ChainOfResponsibility handler_A handler_B)
