cmake_minimum_required(VERSION 3.13)

set(PROJ Rat-In-A-Maze)

project(${PROJ} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)

add_executable(${PROJ}.out main.cpp room.h maze.h)

target_compile_options(${PROJ}.out PRIVATE -g -Wall -Wextra -Werror )


