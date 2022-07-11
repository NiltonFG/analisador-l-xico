cmake_minimum_required(VERSION 3.22)
project(AnalizadorLexico)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(AnalizadorLexico
        listaWorks.h
        listaWorks.c
        main.c
        suportFile.txt)
