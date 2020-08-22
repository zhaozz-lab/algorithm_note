cmake_minimum_required(VERSION 2.8)
project(algorithm_note)

add_definitions(-std=c++11)
# SET(OPENCV_PATH "F:/gazeApp/lib/opencv/build")

add_definitions(/Zi /Od)

set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /Debug")

add_executable(sort ${CMAKE_SOURCE_DIR}/src/sort.cpp)

add_executable(vector_remove ${CMAKE_SOURCE_DIR}/src/vector_remove.cpp)
add_executable(stack ${CMAKE_SOURCE_DIR}/src/stack.cpp)
add_executable(dfs ${CMAKE_SOURCE_DIR}/src/dfs.cpp)
add_executable(bfs ${CMAKE_SOURCE_DIR}/src/bfs.cpp)
add_executable(dp ${CMAKE_SOURCE_DIR}/src/dp.cpp)

add_executable(trees ${CMAKE_SOURCE_DIR}/src/trees.cpp)
add_executable(reconstructTree ${CMAKE_SOURCE_DIR}/src/reconstructtree.cpp)
add_executable(graph ${CMAKE_SOURCE_DIR}/src/graph.cpp)
add_executable(graph_dfs ${CMAKE_SOURCE_DIR}/src/graph_dfs.cpp)
add_executable(graph_bfs ${CMAKE_SOURCE_DIR}/src/graph_bfs.cpp)

add_executable(multithread_helloworld ${CMAKE_SOURCE_DIR}/src/parallel/multi_hello.cpp)
add_executable(return_value ${CMAKE_SOURCE_DIR}/src/parallel/returnvalue.cpp)