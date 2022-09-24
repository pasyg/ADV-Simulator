cmake_minimum_required(VERSION 3.0.0)
project(Simulator VERSION 0.1.0)

set (CMAKE_CXX_STANDARD 20)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

#set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# GCC flag
# set(CMAKE_CXX_FLAGS -pthread)

INCLUDE_DIRECTORIES(
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/src/attackmove
    ${PROJECT_SOURCE_DIR}/src/battle
    
    ${PROJECT_SOURCE_DIR}/src/data
    ${PROJECT_SOURCE_DIR}/src/pokemon
    ${PROJECT_SOURCE_DIR}/src/string_conversions
    ${PROJECT_SOURCE_DIR}/src/team
    ${PROJECT_SOURCE_DIR}/src/tools
    ${PROJECT_SOURCE_DIR}/src/test 
)


set(EXECUTABLE_OUTPUT_PATH ../)

set(Simulator_SOURCES
    src/attackmove/attackmove.cpp
    src/attackmove/effectiveness.cpp

    src/battle/battle.cpp
    src/battle/damage_calc.cpp
    src/battle/decide_move.cpp
    src/battle/log.cpp
    src/battle/turn.cpp
    src/battle/use_move.cpp

    src/data/base_stats.cpp
    src/data/item.cpp
    src/data/moves.cpp
    src/data/species.cpp

    src/pokemon/pokemon.cpp

    src/string_conversions/ability.cpp
    src/string_conversions/gender.cpp
    src/string_conversions/item.cpp
    src/string_conversions/moves.cpp
    src/string_conversions/nature.cpp
    src/string_conversions/species.cpp
    src/string_conversions/status.cpp
    src/string_conversions/string_conversions.cpp
    src/string_conversions/type.cpp
    src/string_conversions/weather.cpp

    src/tools/import.cpp
    src/tools/rng.cpp

    src/team/team.cpp

    src/main.cpp
    
    src/test/import_test.cpp
    src/test/move_test.cpp
    src/test/test.cpp)

add_executable(Simulator ${Simulator_SOURCES})