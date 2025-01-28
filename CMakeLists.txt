cmake_minimum_required(VERSION 3.14)
project(coded VERSION 1.0.0)

include_directories(include)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)
add_subdirectory(tests)
