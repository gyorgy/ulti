cmake_minimum_required(VERSION 3.7)

project(libulti)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        engine.h
        engine.cc
        player.h
        player.cc
        macros.h
        game_state.h
        game_state.cc
        player_state.h
        player_state.cc
        cards.h
        bits.h bids.h cards.cc)

add_library(ulti STATIC ${SOURCE_FILES})