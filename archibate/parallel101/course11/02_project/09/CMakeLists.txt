cmake_minimum_required(VERSION 3.15)
project(hellocmake VERSION 0.2.3)

message("PROJECT_NAME: ${PROJECT_NAME}")
message("PROJECT_VERSION: ${PROJECT_VERSION}")
message("PROJECT_SOURCE_DIR": ${PROJECT_SOURCE_DIR})
message("PROJECT_BINARY_DIR": ${PROJECT_BINARY_DIR})
message("hellocmake_VERSION: ${hellocmake_VERSION}")
message("hellocmake_SOURCE_DIR: ${hellocmake_SOURCE_DIR}")
message("hellocmake_BINARY_DIR: ${hellocmake_BINARY_DIR}")
add_executable(main main.cpp)

