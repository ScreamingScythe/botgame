cmake_minimum_required(VERSION 2.6)

project(GamePlay)

include_directories( include src ${CMAKE_SOURCE_DIR}/../gamedata/include )
link_directories( ${CMAKE_SOURCE_DIR}/../gamedata/build )

# GamePlay library

set(GAMEPLAY_SOURCES
  src/Test.cpp
)

add_library(gameplay SHARED ${GAMEPLAY_SOURCES})

target_link_libraries(gameplay gamedata)