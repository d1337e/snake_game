#include "Snake.h"

Snake::Snake(const int x, const int y) : dx(0), dy(1) {
    body.push_back({x, y});
    //std::cout << "Snake created at: " << x << ", " << y << std::endl;
}

void Snake::move() {
    auto [x, y] = body[0]; // проверим, что тут
    //std::cout << "Moving from: " << x << ", " << y << std::endl;

    int newX = x + dx;
    int newY = y + dy;

    body.insert(body.begin(), {newX, newY});
    if (!growing)
        body.pop_back();
    else
        growing = false;
}

void Snake::grow() {
    growing = true;
}

bool Snake::checkCollision(const int width, const int height) const {
    auto [x, y] = body[0];
    return x < 0 || x >= width || y < 0 || y >= height;
}

bool Snake::checkSelfCollision() const {
    int xHead = body[0].first;
    int yHead = body[0].second;
    for (auto i = 1; i < body.size(); i++) {
        if (xHead == body[i].first && yHead == body[i].second) return true;
    }
    return false;
}

const std::vector<std::pair<int, int>>& Snake::getBody() const {
    return body;
}

void Snake::setDirection(const int x, const int y) {
    // Не разрешаем разворот на 180
    if ((x == 0 && y == 1 && dx == 0 && dy == -1) ||  // вправо ← влево
        (x == 0 && y == -1 && dx == 0 && dy == 1) || // влево ← вправо
        (x == 1 && y == 0 && dx == -1 && dy == 0) || // вниз ← вверх
        (x == -1 && y == 0 && dx == 1 && dy == 0)) { // вверх ← вниз
        return; // не меняем направление
    }
    dx = x;
    dy = y;
}

int Snake::getDx() {
    //std::cout << "getDx: " << dx << std::endl;
    return dx;
}

int Snake::getDy() {
    //std::cout << "getDy: " << dy << std::endl;
    return dy;
}