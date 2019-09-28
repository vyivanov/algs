cmake_minimum_required(VERSION 3.12)
project(algs CXX)

set(CMAKE_CXX_STANDARD 17)
find_package(Threads)

set(ALG_SOURCES adt/queue.cpp
                adt/tpool.cpp)

set(TST_SOURCES main.cpp
                adt/test_tpool.cpp)

add_library(algs SHARED ${ALG_SOURCES})
add_executable(tests ${TST_SOURCES})

target_link_libraries(tests algs ${CMAKE_THREAD_LIBS_INIT})
