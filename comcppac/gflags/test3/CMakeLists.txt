cmake_minimum_required(VERSION 3.12)
project(test3 LANGUAGES CXX)

find_package(gflags REQUIRED)
add_executable(t3 main.cpp control_flags.cpp)
target_link_libraries(t3 gflags)

