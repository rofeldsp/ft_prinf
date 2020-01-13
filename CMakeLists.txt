cmake_minimum_required(VERSION 3.15)
project(printf_owngit C)

set(CMAKE_C_STANDARD 99)

add_executable(printf_owngit ft_printf.c list.h main.c author.c)