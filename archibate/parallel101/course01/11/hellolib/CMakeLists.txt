add_library(hellolib STATIC hello.cpp)
# to make parent directory to contain hellolib
target_include_directories(hellolib PUBLIC .)  

