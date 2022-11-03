add_executable(main main.cpp)

#this is cmake way
set_property(TARGET main PROPERTY CXX_STANDARD 17)     #right
#this conflicits cmake's default method
#this cannot cross-platforms
#target_compile_options(main PUBLIC "-std=c++17") #wrong
set_property(TARGET main PROPERTY CUDA_ARCHITECTURES 75) # right


#target_compile_options(main PUBLIC "-arch=sm_75") #wrong


