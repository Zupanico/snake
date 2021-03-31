cmake_minimum_required(VERSION 3.17)
project(snake)

set(CMAKE_CXX_STANDARD 20)

add_executable(snake main.cpp game.cpp game.h snake.cpp snake.h apple.cpp apple.h point.cpp point.h rectangle.cpp rectangle.h)