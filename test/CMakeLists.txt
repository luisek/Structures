include_directories (${STRUCTURES_SOURCE_DIR}/src
                     ${gtest_SOURCE_DIR}/include
                     )

add_executable (Test stack_test.cpp list_test.cpp)
target_link_libraries (Test
                       Stack
					   List
                       gtest_main
					   gtest
                       )