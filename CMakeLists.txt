cmake_minimum_required(VERSION 3.5)

project(baz LANGUAGES CXX VERSION 0.0.1)

find_package(Catch2 REQUIRED)
add_executable(tests test2.cpp)
target_link_libraries(tests PUBLIC Catch2::Catch2WithMain)
target_link_libraries(tests PUBLIC Catch2::Catch2)
include(CTest)
include(ParseAndAddCatchTests)