cmake_minimum_required(VERSION 3.7)
project(testbed)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cc testbed.h testbed.cc)

add_executable(testbed ${SOURCE_FILES})