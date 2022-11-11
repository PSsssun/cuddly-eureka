add_executable(main)
file(GLOB sources CONFIGURE_DEPENDS *.cpp *.h) # configure adaptive to later changes in *.cpp/*.h
target_sources(main PUBLIC ${sources})


