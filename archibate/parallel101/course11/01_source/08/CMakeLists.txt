add_executable(main)
file(GLOB sources CONFIGURE_DEPENDS *.cpp *.h lib/*.cpp lib/.*h)
target_sources(main PUBLIC ${sources})


