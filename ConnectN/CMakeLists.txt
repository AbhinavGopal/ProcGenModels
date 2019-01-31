cmake_minimum_required(VERSION 3.13)
project(ConnectN C)

set(CMAKE_C_STANDARD 11)

add_executable(ConnectN main.c win.c win.h Board.h Board.c)