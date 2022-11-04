cmake_minimum_required(VERSION 3.15)
project(hellocmake LANGUAGES CXX)
#set(CMAKE_BUILD_TYPE Debug) 
message("PATH is: $ENV{PATH}")
message("CMAKE_BUILD_TYPE is: ${CMAKE_BUILD_TYPE}")  #this fails

add_executable(main main.cpp)
