cmake_minimum_required(VERSION 3.15)
project(AED1_LP1 C)

set(CMAKE_C_STANDARD 99)

add_executable(AED1_LP1 main.c structs.h buildings.c buildings.h events.c events.h studios.c studios.h)