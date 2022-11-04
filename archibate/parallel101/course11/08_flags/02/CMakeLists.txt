add_executable(main)
file(GLOB sources CONFIGURE_DEPENDS *.cpp *.h)
target_sources(main PUBLIC ${sources})

if (CMAKE_SYSTEM_NAME MATCHES "Windows") #(WIN32)
    target_compile_definitions(main PUBLIC MY_NAME="Bill Gates")
elseif (CMAKE_SYSTEM_NAME MATCHES "Linux") #(UNIX AND NOT APPLE)
    target_compile_definitions(main PUBLIC MY_NAME="Linus Torvalds")
elseif (CMAKE_SYSTEM_NAME MATCHES "Darwin")  # (APPLE)
    target_compile_definitions(main PUBLIC MY_NAME="Steve Jobs")

endif()
