cmake_minimum_required(VERSION 2.6)

project(GameData)

find_package(Boost REQUIRED)

include_directories( include src ${Boost_INCLUDE_DIR} )

# GameData library

set(GAMEDATA_SOURCES
    src/Base/RefCountObject.cpp
    src/Io/Values.cpp
    src/Object.cpp
    src/World.cpp
)

add_library(gamedata SHARED ${GAMEDATA_SOURCES})

add_executable(gamedata-io-values-test src/Io/ValuesTest.cpp)
target_link_libraries(gamedata-io-values-test gamedata)
