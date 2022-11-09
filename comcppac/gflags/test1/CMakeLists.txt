cmake_minimum_required(VERSION 3.12)

project(hellogflags LANGUAGES CXX)

find_package(gflags COMPONENTS nothreads_static)

add_executable(t1 test1.cpp)
target_link_libraries(t1 gflags)
