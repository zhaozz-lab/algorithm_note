#1.cmake verson，指定cmake的最小版本号 
cmake_minimum_required(VERSION 2.8)

#2.project name，指定项目的名称，一般和项目的文件夹名称对应
project(testdll C CXX)

#3.set environment variable，设置环境变量
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#4.include头文件目录 
include_directories(
	               ${CMAKE_CURRENT_LIST_DIR}/src/include
                    )

#5.library目录及name名称
link_directories(${CMAKE_CURRENT_LIST_DIR}/build/Release
                 )


#7.2.add library file，编译为动态库
# add_executable(mtcnn_ncnn SHARED ${MTCNN_COMPILE_CODE})

#8.add link library，添加工程所依赖的库
add_library(add SHARED ${CMAKE_CURRENT_LIST_DIR}/src/add.cpp)

link_directories(${CMAKE_CURRENT_LIST_DIR}/build/Release)
                 
add_executable(dlltest src/main.cpp)
target_link_libraries(dlltest add)