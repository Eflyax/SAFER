cmake_minimum_required(VERSION 3.4)
project(SAFER)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES SAFERK64.c)
add_executable(cecko ${SOURCE_FILES})