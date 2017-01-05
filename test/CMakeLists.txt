set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)

include_directories (${STRUCTURES_SOURCE_DIR}/src
                     ${Boost_INCLUDE_DIRS}
                     )

add_executable (Test stack_test.cpp)
target_link_libraries (Test
                       Stack
                       ${Boost_LIBRARIES}
                       )