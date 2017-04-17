cmake_minimum_required(VERSION 3.7)

include_directories(.)

link_directories(libulti libkubler)

add_subdirectory(libulti)
add_subdirectory(libkubler)
add_subdirectory(testbed)