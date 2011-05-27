cmake_minimum_required(VERSION 2.6)

project(VmLua)

include_directories( include src ${CMAKE_SOURCE_DIR}/../vmapi/include ${CMAKE_SOURCE_DIR}/../gameplay/include ${CMAKE_SOURCE_DIR}/../gamedata/include )
link_directories( ${CMAKE_SOURCE_DIR}/../gameplay/build ${CMAKE_SOURCE_DIR}/../gamedata/build )

# VmLua library

set(VMLUA_SOURCES
  src/Test.cpp
)

add_library(vmlua SHARED ${VMLUA_SOURCES})

target_link_libraries(vmlua gameplay gamedata) 
