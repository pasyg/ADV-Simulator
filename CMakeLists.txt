cmake_minimum_required(VERSION 3.0.0)
project(Simulator VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

INCLUDE_DIRECTORIES(
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/string_conversions
    ${PROJECT_SOURCE_DIR}/bounded-integer/include
)

LINK_DIRECTORIES(
    ${PROJECT_SOURCE_DIR}/src
)

#add_compile_options("$<$<CONFIG:DEBUG>:-DBENCHMARK>")

set(EXECUTABLE_OUTPUT_PATH ../)

add_executable(Simulator 
    src/main.cpp
    src/attackmove.cpp
    src/base_stats.cpp
    src/moves.cpp
    src/pokemon.cpp
    src/state.cpp
    src/rng.cpp
    
    string_conversions/ability.cpp
    string_conversions/gender.cpp
    string_conversions/item.cpp
    string_conversions/moves.cpp
    string_conversions/nature.cpp
    string_conversions/species.cpp
    string_conversions/status.cpp
    string_conversions/type.cpp)

TARGET_LINK_LIBRARIES(Simulator
    
)