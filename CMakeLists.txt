cmake_minimum_required(VERSION 3.17.5)

project(1_homework C CXX)

set(CMAKE_CXX_FLAGS "-Wall -Wno-unknown-pragmas -Wno-sign-compare -Woverloaded-virtual -Wwrite-strings -Wno-unused -Werror -Wpedantic")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")

add_subdirectory(src)
add_subdirectory(cmd)

add_subdirectory(tests)
enable_testing()
