cmake_minimum_required(VERSION 2.6)

project(GameData)

find_package(Boost REQUIRED)

include_directories( include src ${Boost_INCLUDE_DIR} )

# GameData library

set(GAMEDATA_SOURCES
    include/Object.h
    include/Position.h
    include/World.h
    src/Object.cpp
    src/World.cpp
)

add_library(gamedata SHARED ${GAMEDATA_SOURCES})
