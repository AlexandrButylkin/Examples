cmake_minimum_required(VERSION 3.20)
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")
project(Shapes LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_FLAGS "-lgdi32")

add_executable(Shapes main.cpp Primitives.cpp Primitives.h Figures.h Figures.cpp Drawer.cpp Drawer.h Tests.h Tests.cpp)
