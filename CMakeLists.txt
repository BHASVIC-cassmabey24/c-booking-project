cmake_minimum_required(VERSION 3.29)
project(idkworkorwtv C)

set(CMAKE_C_STANDARD 11)

add_executable(idkworkorwtv main.c
        common.h
        common.c
        check_in.c

        book_table.c
)
