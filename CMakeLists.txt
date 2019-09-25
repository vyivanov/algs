project(algs CXX)

set(ALG_SOURCES
    adt/queue.cpp)

set(TST_SOURCES main.cpp)

add_library(algs SHARED ${ALG_SOURCES})
add_executable(tests ${TST_SOURCES})

target_link_libraries(tests algs)
