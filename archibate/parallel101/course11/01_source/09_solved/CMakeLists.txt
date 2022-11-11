add_executable(main)
file(GLOB_RECURSE sources CONFIGURE_DEPENDS src/*.cpp)# *.h)
target_sources(main PUBLIC ${sources})


