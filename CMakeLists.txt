cmake_minimum_required(VERSION 3.26)
project(prak)

set(CMAKE_CXX_STANDARD 17)

# Основная программа
add_executable(main_app main.cpp)

# Первая задача
add_executable(first_app first/first.cpp
        three/three.cpp
        four/four.cpp
        five/five.cpp
        "six/perviy .cpp"
        six/vtoroy.cpp
        six/tretiy.cpp
        seven/seven.cpp)

# Вторая задача
add_executable(second_app second/second.cpp)

#Третья задача
add_executable(three, three/three.cpp)

#Четвертая задача
add_executable(four, four/four.cpp)

#Пятая задача
add_executable(five, five/five.cpp)