cmake_minimum_required (VERSION 3.12)
project (myproj VERSION 1.0)

find_package (glog REQUIRED)

add_executable (myapp test.cpp)
target_link_libraries (myapp glog::glog)