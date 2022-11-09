cmake_minimum_required(VERSION 3.12)

project(test2 LANGUAGES CXX)

find_package(gflags REQUIRED)

add_executable(t2 main.cpp)

target_link_libraries(t2 gflags)
