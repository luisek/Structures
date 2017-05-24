include_directories (${STRUCTURES_SOURCE_DIR}/src
                     ${gtest_SOURCE_DIR}/include
                     )

add_executable (Test stackImpl_test.cpp stack_test.cpp list_test.cpp)
target_link_libraries (Test
                       StackImpl
                       Stack
					   List
                       gtest_main
					   gtest
                       )