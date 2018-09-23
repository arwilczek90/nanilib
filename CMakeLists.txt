cmake_minimum_required(VERSION 3.12)
project(nanilib C)

set(CMAKE_C_STANDARD 11)

add_library(nanilib SHARED nanilib.c nanilib.h nani.c)
add_executable(nani nani.c nani.c)