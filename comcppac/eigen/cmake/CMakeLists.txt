cmake_minimum_required(VERSION 3.12)
project(hello_eigen)

find_package(Eigen3 3.3)

add_executable(a first_program.cpp)
target_link_libraries(a Eigen3::Eigen)

