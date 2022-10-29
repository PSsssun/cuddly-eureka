cmake_minimum_required(VERSION 3.12)
project(hellocmake LANGUAGES CXX)

#create a libhellolib.o 
add_library(hellolib STATIC hello.cpp)
#build a.out from main.cpp 
add_executable(a.out main.cpp)
#link libhellolib to a.out
target_link_libraries(a.out PUBLIC hellolib)


