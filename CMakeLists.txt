cmake_minimum_required(VERSION 3.26)
project(prak)

set(CMAKE_CXX_STANDARD 17)

# Основная программа
add_executable(main_app main.cpp)

# Первая лабораторная
add_executable(first_app first/first.cpp
        three/three.cpp)

# Вторая лабораторная
add_executable(second_app second/second.cpp)
