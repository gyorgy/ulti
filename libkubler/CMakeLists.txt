cmake_minimum_required(VERSION 3.7)

project(libkubler)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES kubler.h kubler.cc)

add_library(kubler STATIC ${SOURCE_FILES})

target_link_libraries(kubler ulti)