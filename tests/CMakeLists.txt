set(TEST_SRC	test_main.cpp
				test_slist.cpp)

add_executable(tests ${TEST_SRC})
target_link_libraries(tests collections CppUTest)

add_custom_command(TARGET tests POST_BUILD COMMAND ${CMAKE_CURRENT_BINARY_DIR}/tests -v)

add_test(all ${CMAKE_CURRENT_BINARY_DIR}/tests -v)
