add_library (Stack stack.cpp stack.h)
add_executable(demo main.cpp)
target_link_libraries(demo Stack)