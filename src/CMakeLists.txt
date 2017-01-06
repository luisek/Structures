add_library (Stack Stack.cpp Stack.hpp)
add_executable(demo main.cpp)
target_link_libraries(demo Stack)
