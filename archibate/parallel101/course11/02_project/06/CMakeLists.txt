cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)  # enable extensions from gcc, normally OFF

project(hellocmake LANGUAGES CXX)

add_executable(main main.cpp)


