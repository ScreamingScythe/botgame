cmake_minimum_required(VERSION 2.6)

project(VmApi)

include_directories( include src ${CMAKE_SOURCE_DIR}/../gameplay/include ${CMAKE_SOURCE_DIR}/../gamedata/include )
link_directories( ${CMAKE_SOURCE_DIR}/../gameplay/build ${CMAKE_SOURCE_DIR}/../gamedata/build )
