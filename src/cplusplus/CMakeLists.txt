#1.cmake verson，指定cmake的最小版本号 
cmake_minimum_required(VERSION 2.8)

#2.project name，指定项目的名称，一般和项目的文件夹名称对应
project(cplusplus C CXX)

#3.set environment variable，设置环境变量
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#4.include头文件目录 
include_directories(
	               ${CMAKE_CURRENT_LIST_DIR}/src/include
                    )

#5.library目录及name名称
link_directories(${CMAKE_CURRENT_LIST_DIR}/build/Release
                 )
                 
add_executable(union src/union.cpp)