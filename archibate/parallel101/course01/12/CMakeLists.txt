cmake_minimum_required(VERSION 3.12)
project(hellocmake LANGUAGES CXX)

add_executable(a.out main.cpp)
#this adds glm/include/glm/ to target scope
#glm/include/glm contains a CMakeLists.txt for glm
target_include_directories(a.out PUBLIC glm/include/glm) # glm/include works also okay combined with #include in main.cpp



