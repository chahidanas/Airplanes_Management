cmake_minimum_required(VERSION 3.28)
project(ChahidAirlines)

set(CMAKE_CXX_STANDARD 14)

add_executable(ChahidAirlines main.cpp
        introLoad.h
        introLoad.cpp
        airlines.cpp
        airlines.h)
