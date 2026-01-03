#include "Food.h"

Food::Food() : x(0), y(0), gen(std::random_device{}()), dis(0, 99) {}

std::pair<int, int> Food::getPosition() const {
    return {this->x, this->y};
}

void Food::generate(const int width, const int height, const Snake& snake) {
    dis = std::uniform_int_distribution<>(0, width - 1);
    const auto& snakeBody = snake.getBody();
    do {
        x = dis(gen);
        y = std::uniform_int_distribution<>(0, height - 1)(gen);

        bool onSnake = false;
        for (const auto& segment : snakeBody) {
            if (segment.first == x && segment.second == y) {
                onSnake = true;
                break;
            }
        }
        if (!onSnake) break;
    } while (true);

}