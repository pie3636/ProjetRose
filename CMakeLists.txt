cmake_minimum_required(VERSION 3.8)
project(ProjetRose)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp Game.cpp Game.h Neural.cpp Neural.h Simul.h Simul.cpp IA.h IA.cpp)
add_executable(ProjetRose ${SOURCE_FILES})