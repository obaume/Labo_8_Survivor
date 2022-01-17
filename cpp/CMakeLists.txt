cmake_minimum_required(VERSION 3.20)
project(test)

set(CMAKE_CXX_STANDARD 20)

add_executable(test main.cpp Robot.cpp Robot.h Plateau.cpp Plateau.h Aleatoire.cpp
        Aleatoire.h preferences.h saisie.h saisie.cpp)
