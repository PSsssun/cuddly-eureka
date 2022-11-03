add_executable(main main.cpp)

find_package(TBB REQUIRED) # this will search configuration file: /usr/lib/cmake/TBB/TBBConfig.cmake 
# then it will create a pseudo object TBB::tbb ( indeed it links to /usr/lib/libtbb.so)
target_link_libraries(main PUBLIC TBB::tbb)


#TBB::tbb 是一个伪对象(imported)，除了他会指向 /usr/lib/libtbb.so 之外，TBBConfig.cmake 还会给 TBB::tbb 添加一些 PUBLIC 属性，用于让链接了他的对象带上一些 flag 之类的。
#比如，TBB 安装在 /opt/tbb 目录下，头文件在 /opt/tbb/include 里，那么这时 TBBConfig.cmake 里就会有：
#target_include_directories(TBB::tbb PUBLIC /opt/tbb/include)
#这样 main 在链接了 TBB::tbb 的时候也会被“传染”上 /opt/tbb/include 这个目录，不用调用者手动添加了。
#再比如，TBB::tbb 链接了另一个库 Blosc::blosc，那这个库也会自动链接到 main 上，无需调用者手动添加。
