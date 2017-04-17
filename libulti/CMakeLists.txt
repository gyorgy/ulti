cmake_minimum_required(VERSION 3.7)

project(libulti)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES engine.h engine.cc player.h player.cc)

add_library(ulti STATIC ${SOURCE_FILES})