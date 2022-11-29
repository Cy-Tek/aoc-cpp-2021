cmake_minimum_required(VERSION 3.24)
project(aoc_cpp_2021)

set(CMAKE_CXX_STANDARD 23)

add_executable(aoc_cpp_2021 main.cpp days/Day.hpp days/Day1.cc Parser.hpp days/Day2.cc days/Day3.cc Ranges.hpp days/Day4.cc)
add_subdirectory(tests)