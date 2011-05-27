cmake_minimum_required(VERSION 2.6)

project(GameData)

include_directories( include src )

# GameData library

set(GAMEDATA_SOURCES
  src/Test.cpp
)

add_library(gamedata SHARED ${GAMEDATA_SOURCES})
