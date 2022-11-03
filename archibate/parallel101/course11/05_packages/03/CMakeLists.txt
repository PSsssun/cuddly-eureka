add_executable(main main.cpp)

#it will search TBBConfig.cmake instead of FindTBB.cmake 
find_package(TBB CONFIG REQUIRED)

target_link_libraries(main PUBLIC TBB::tbb)
