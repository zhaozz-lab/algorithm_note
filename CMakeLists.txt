cmake_minimum_required(VERSION 2.8)
project(algorithm_note)

add_definitions(-std=c++11)

add_definitions(/Zi /Od)

set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /Debug")

add_subdirectory(src/algorithmnote)
add_subdirectory(src/parallel)