find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

add_executable(tests tests.cpp run_tests.cpp)

target_link_libraries(tests ${GTEST_LIBRARIES} Threads::Threads storage input)

add_test(NAME storage_tests COMMAND storage_tests)