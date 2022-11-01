cmake_minimum_required(VERSION 3.12)
#required standard for cmake 
project(hellocmake LANGUAGES CXX)
#create project for cmake (if not , cmake will pretend there is one project(Project))
add_executable(a.out main.cpp hello.cpp)
#this line is cruical 



