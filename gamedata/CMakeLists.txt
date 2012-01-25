cmake_minimum_required(VERSION 2.6)

project(GameData)

find_package(Boost REQUIRED)

include_directories( include src ${Boost_INCLUDE_DIR} )

# GameData library

set(GAMEDATA_SOURCES
    src/Base/RefCountObject.cpp
    src/Object.cpp
    src/PhysicalObject.cpp
    src/World.cpp
    src/Value.cpp
)

add_library(gamedata SHARED ${GAMEDATA_SOURCES})

add_executable(gamedata-values-test src/ValuesTest.cpp)
target_link_libraries(gamedata-values-test gamedata)

add_executable(gamedata-objects-test src/ObjectsTest.cpp)
target_link_libraries(gamedata-objects-test gamedata)
