cmake_minimum_required(VERSION 3.15)
project(M2OEP2-balbritt)

set(CMAKE_CXX_STANDARD 17)

add_executable(M2OEP2-balbritt main.cpp
        data/entity.h
        data/entity.cpp
        data/enemy.cpp
        data/enemy.h
        data/player.h
        data/player.cpp
        data/input.h
)

add_executable(M2OEP2test-balbritt testing.cpp
        data/entity.h
        data/entity.cpp
        data/enemy.cpp
        data/enemy.h
        data/player.h
        data/player.cpp
        testing.cpp
        data/input.h
)