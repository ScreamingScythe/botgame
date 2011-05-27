cmake_minimum_required(VERSION 2.6)

project(Gui)

include_directories( include src ${CMAKE_SOURCE_DIR}/../gamedata/include )
link_directories( ${CMAKE_SOURCE_DIR}/../gamedata/build )

# Gui library

set(GUI_SOURCES
  src/Test.cpp
)

add_executable(gui ${GUI_SOURCES})

target_link_libraries(gui gamedata) 
