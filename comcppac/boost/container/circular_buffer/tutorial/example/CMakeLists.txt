cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 11)
project(heyboost LANGUAGES CXX)
find_package(Boost REQUIRED COMPONENTS container)
add_executable(myapp main.cpp)
target_link_libraries(myapp Boost::container)

