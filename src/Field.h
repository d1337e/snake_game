#pragma once
#include <vector>
#include "ncurses.h"
#include <iostream>

class Field {
private:
    int width, height;
    std::vector<std::vector<char>> digs;
    void init();
public:
    Field(const int width = 20, const int height = 20);
    ~Field() = default;
    void draw() const;
    int getWidth() const;
    int getHeight() const;
    void clear();
    void set(const int x, const int y, const char c);
    void drawNcurses();
};