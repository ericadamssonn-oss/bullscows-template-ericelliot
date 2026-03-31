cmake_minimum_required(VERSION 3.12)
project(bullscows C)

set(CMAKE_C_STANDARD 99)

add_executable(bullscows bullscows.c)
target_link_libraries(bullscows m)
