cmake_minimum_required(VERSION 3.7)

include_directories(.)

add_compile_options(-Wall)

link_directories(libulti libkubler)

set(CMAKE_CXX_FLAGS_DEBUG "-Wall -g -O0")

add_subdirectory(libulti)
add_subdirectory(libkubler)
add_subdirectory(testbed)