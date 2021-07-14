cmake_minimum_required(VERSION 3.16)
project(Eight_Digits)

set(CMAKE_CXX_STANDARD 20)

add_executable(Eight_Digits main.cpp Board.cpp Board.h DFS.cpp DFS.h BFS.cpp BFS.h)
