#include "Game.h"

Game::Game() : field(), snake(10, 10), food() {
    food.generate(field.getWidth(), field.getHeight(), snake);
}

void Game::run() {
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);

    while (!gameOver) {
        input();
        logic();
        draw();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    endwin();
}

void Game::logic() {
    auto head = snake.getBody()[0];
    //std::cout << "Head position: " << head.first << ", " << head.second << std::endl;
    int nextX = head.first + snake.getDx();
    int nextY = head.second + snake.getDy();
    //std::cout << "Current direction: " << snake.getDx() << ", " << snake.getDy() << std::endl;
    if (nextX < 0 || nextX >= field.getWidth() || nextY < 0 || nextY >= field.getHeight()) {
        //std::cout << "Collision with wall at: " << nextX << ", " << nextY << std::endl;
        gameOver = true;
        return;
    }

    snake.move();

    auto newHead = snake.getBody()[0];
    auto foodPos = food.getPosition();
    if (newHead.first == foodPos.first && newHead.second == foodPos.second) {
        //std::cout << "Food eaten!" << std::endl;
        snake.grow();
        food.generate(field.getWidth(), field.getHeight(), snake);
    }

    if (snake.checkSelfCollision()) {
        //std::cout << "Self collision!" << std::endl;
        gameOver = true;
    }
}

void Game::input() {
    int ch;
    while((ch = getch()) != ERR) {
        switch (ch) {
            case 'w': snake.setDirection(0, -1); break;
            case 's': snake.setDirection(0, 1); break;
            case 'a': snake.setDirection(-1, 0); break;
            case 'd': snake.setDirection(1, 0); break;
        }
    }
}
void Game::draw() {
    field.clear();

    for (auto i = 0; i < snake.getBody().size(); i++) {
        auto [x, y] = snake.getBody()[i];
        if (i == 0)
            field.set(x, y, 'X');
        else
            field.set(x, y, 'o');
    }

    auto [fx, fy] = food.getPosition();
    field.set(fx, fy, 'F');

    field.drawNcurses();
}