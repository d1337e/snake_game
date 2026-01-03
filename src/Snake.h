#pragma once
#include <vector>
#include <iostream>

class Snake {
private:
    std::vector<std::pair<int, int>> body;
    int dx = 1, dy = 0;
    bool growing = false;
public:
    Snake(const int x, const int y);
    ~Snake() = default;
    void move();
    void grow();
    bool checkCollision(const int width, const int height) const;
    bool checkSelfCollision() const;
    const std::vector<std::pair<int, int>>& getBody() const;
    void setDirection(const int x, const int y);
    int getDx();
    int getDy();
};