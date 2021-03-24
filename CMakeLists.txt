cmake_minimum_required(VERSION 3.17)
project(game_of_life)

set(CMAKE_CXX_STANDARD 14)

add_executable(game_of_life main.cc Renderer.h GameEngine.h GameOfLife.cc GameOfLife.h)