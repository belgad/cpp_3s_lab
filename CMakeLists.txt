cmake_minimum_required(VERSION 3.12)
project(cpp_3s_lab)

set(CMAKE_CXX_STANDARD 14)

add_executable(main main.cpp magic.hpp)

add_library(Vector STATIC Vector.cpp Vector.hpp)
add_library(Matrix STATIC Matrix.cpp Matrix.hpp Vector.cpp Vector.hpp)

target_link_libraries(main Matrix)
