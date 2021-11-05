cmake_minimum_required(VERSION 3.0.0)
project(Simulator VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

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
)

add_compile_options("$<$<CONFIG:DEBUG>:-DBENCHMARK>")
add_compile_options("$<$<CONFIG:RELEASE>:-DBENCHMARK>")

set(EXECUTABLE_OUTPUT_PATH ../)

add_executable(Simulator 
    src/attackmove/attackmove.cpp
    src/attackmove/effectiveness.cpp

    src/battle/battle.cpp
    src/battle/damage_calc.cpp
    src/battle/turn.cpp
    src/battle/use_move.cpp

    src/data/base_stats.cpp
    src/data/category.cpp
    src/data/item.cpp
    src/data/moves.cpp

    src/pokemon/pokemon.cpp

    src/string_conversions/ability.cpp
    src/string_conversions/gender.cpp
    src/string_conversions/item.cpp
    src/string_conversions/moves.cpp
    src/string_conversions/nature.cpp
    src/string_conversions/species.cpp
    src/string_conversions/status.cpp
    src/string_conversions/type.cpp

    src/tools/rng.cpp
    src/tools/state.cpp
    src/tools/import.cpp

    src/team/team.cpp

    src/main.cpp)