project(parallel)

cmake_minimum_required(VERSION 2.8)

add_definitions(/Zi /Od)

set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /Debug")
SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)

add_executable(multithread_helloworld ${PROJECT_SOURCE_DIR}/multi_hello.cpp)
SET_PROPERTY(TARGET multithread_helloworld PROPERTY FOLDER "parallel")

add_executable(return_value ${PROJECT_SOURCE_DIR}/returnvalue.cpp)
SET_PROPERTY(TARGET return_value PROPERTY FOLDER "parallel")


include_directories(${PROJECT_SOURCE_DIR}/3rdparty/pthreads/include)
link_directories(${PROJECT_SOURCE_DIR}/3rdparty/pthreads/lib)

add_executable(multithread_pthread ${PROJECT_SOURCE_DIR}/multi_hello.cpp)
target_link_libraries(multithread_pthread pthreadVC2)
SET_PROPERTY(TARGET multithread_pthread PROPERTY FOLDER "parallel")

add_executable(multithread_parameter ${PROJECT_SOURCE_DIR}/multi_parameter.cpp)
SET_PROPERTY(TARGET multithread_parameter PROPERTY FOLDER "parallel")


add_executable(sharedata1 ${PROJECT_SOURCE_DIR}/sharedata1.cpp)
target_link_libraries(sharedata1 pthreadVC2)
SET_PROPERTY(TARGET sharedata1 PROPERTY FOLDER "parallel")

add_executable(concurrent_base_lock ${PROJECT_SOURCE_DIR}/concurrent_base_lock.cpp)
target_link_libraries(concurrent_base_lock pthreadVC2)
SET_PROPERTY(TARGET concurrent_base_lock PROPERTY FOLDER "parallel")

add_executable(lazycounter_lock ${PROJECT_SOURCE_DIR}/lazycounter_lock.cpp)
target_link_libraries(lazycounter_lock pthreadVC2)
SET_PROPERTY(TARGET lazycounter_lock PROPERTY FOLDER "parallel")


add_executable(condition_variable ${PROJECT_SOURCE_DIR}/condition_variable.cpp)
target_link_libraries(condition_variable pthreadVC2)
SET_PROPERTY(TARGET condition_variable PROPERTY FOLDER "parallel")