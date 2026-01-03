#pragma once
#include <iostream>
#include <random>
#include "Snake.h"

class Food {
private:
    int x, y;
    std::mt19937 gen;
    std::uniform_int_distribution<> dis;
public:
    Food();
    ~Food() = default;
    std::pair<int, int> getPosition() const;
    void generate(const int width, const int height, const Snake& snake);
};