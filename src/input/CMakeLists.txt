add_library(input_lib input.h input.c)

target_include_directories(input_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})