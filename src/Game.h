#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include "ncurses.h"
#include "Snake.h"
#include "Field.h"
#include "Food.h"

class Game {
private:
    bool gameOver = false;
    Food food;
    Snake snake;
    Field field;
public:
    Game();
    ~Game() = default;
    void run();
    void input();
    void draw();
    void logic();
};