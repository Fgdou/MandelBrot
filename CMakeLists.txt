cmake_minimum_required(VERSION 3.16)
project(mandelbrot)

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)

add_executable(mandelbrot main.cpp complex.cpp complex.h)
target_link_libraries(mandelbrot ${SDL2_LIBRARIES})