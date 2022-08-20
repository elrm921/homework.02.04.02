cmake_minimum_required(VERSION 3.22.0)
find_package(Catch2 3 REQUIRED)

project(my-tests)
add_executable(tests test.cpp list.cpp)
set_property(TARGET tests PROPERTY CXX_STANDARD 14)
target_link_libraries(tests PRIVATE Catch2::Catch2)
