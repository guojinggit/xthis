cmake_minimum_required(VERSION 3.6)
project(this)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES list.cpp)
add_executable(this ${SOURCE_FILES})