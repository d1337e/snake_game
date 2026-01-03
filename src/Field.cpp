#include "Field.h"

Field::Field(const int width, const int height) {
    if (width > 0 && height > 0) {
        this->width = width;
        this->height = height;
    } else {
        throw std::invalid_argument("Values of Field can't be negative and 0!");
    }
    init();
    //std::cout << "Field created with: " << this->width << "x" << this->height << std::endl;
}

void Field::init() {
    digs.resize(height);
    for (auto i = 0; i < height; i++) {
        digs[i].resize(width);
        for (auto j = 0; j < width; j++) {
            digs[i][j] = '.';
        }
    }
}

void Field::draw() const {
    for (auto i = 0; i < height; i++) {
        for (auto j = 0; j < width; j++) {
            std::cout << digs[i][j];
        }
        std::cout << "\n";
    }
}

int Field::getHeight() const {
    return height;
}

int Field::getWidth() const {
    return width;
}

void Field::clear() {
    for (auto i = 0; i < height; i++) {
        for (auto j = 0; j < width; j++) {
            digs[i][j] = '.';
        }
    }
}

void Field::set(const int x, const int y, const char c) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        digs[y][x] = c;
    }
}

void Field::drawNcurses() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            mvaddch(i, j * 2, digs[i][j]);
            if (j < width - 1) {
                mvaddch(i, j * 2 + 1, ' ');
            }
        }
    }
    refresh();
}