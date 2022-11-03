add_executable(main main.cpp)

find_package(TBB REQUIRED)# COMPONENTS tbb tbbmalloc tbbmalloc_proxy  REQUIRED)

target_link_libraries(main PUBLIC TBB::tbb )# TBB::tbbmalloc TBB::tbbmalloc_proxy)



find_package(Qt5 REQUIRED) #COMPONENTS Widgets Gui REQUIRED)             # or it will fail:  The Qt5 package requires at least one component


target_link_libraries(main PUBLIC Qt5::Widgets Qt5::Gui)


