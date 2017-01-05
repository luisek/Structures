add_library (Stack stack.cpp stack.hpp)
add_executable(demo main.cpp)
target_link_libraries(demo Stack)