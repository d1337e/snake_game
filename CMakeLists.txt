cmake_minimum_required(VERSION 3.12)
project(snake_game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(SOURCES
    src/main.cpp
    src/Field.cpp
    src/Snake.cpp
    src/Game.cpp
    src/Food.cpp
)

add_executable(snake ${SOURCES})
target_link_libraries(snake ${CURSES_LIBRARIES})