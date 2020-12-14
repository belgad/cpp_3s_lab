cmake_minimum_required(VERSION 3.12)
project(cpp_3s_lab)

set(CMAKE_CXX_STANDARD 14)

add_executable(main main.cpp magic.h)

add_library(Vector STATIC Vector.cpp Vector.h)
add_library(Matrix STATIC Matrix.cpp Matrix.h Vector.cpp Vector.h)

target_link_libraries(main Matrix)
