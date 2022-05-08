cmake_minimum_required(VERSION 3.20)
project(projeto_aed_lp C)

set(CMAKE_C_STANDARD 99)

add_executable(projeto_aed_lp main.c main.h dados.c dados.h ficheiros.c ficheiros.h  test/teste1.c test/teste1.h algoritmoGenetico.c algoritmoGenetico.h)
