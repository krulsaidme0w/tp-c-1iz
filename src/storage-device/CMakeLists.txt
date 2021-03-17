add_library(storage storage-device.h storage-device.c)

target_include_directories(storage PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})