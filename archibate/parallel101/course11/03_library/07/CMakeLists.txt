add_library(otherlib STATIC otherlib.cpp)
# with this property, link static to shared will fail
set_property(TARGET otherlib PROPERTY POSITION_INDEPENDENT_CODE ON) 

add_library(mylib SHARED mylib.cpp) # link STATIC LIB to SHARED LIB 
target_link_libraries(mylib PUBLIC otherlib)

add_executable(main main.cpp)
target_link_libraries(main PUBLIC mylib)



