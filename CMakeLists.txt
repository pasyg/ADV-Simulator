cmake_minimum_required(VERSION 3.0.0)
project(Simulator VERSION 0.1.0)

INCLUDE_DIRECTORIES(
    ${PROJECT_SOURCE_DIR}/include
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
    src/rng.cpp)

TARGET_LINK_LIBRARIES(Simulator
    
)