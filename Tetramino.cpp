//
// Created by matti on 30/05/2024.
//

#include "Tetramino.h"

using namespace std;

Tetramino::Tetramino() {
    this->x = 0;
    this->y = 0;
    this->currentForm = 0;
}

int Tetramino::getX() {
    return x;
}

int Tetramino::getY() {
    return y;
}

int Tetramino::getCurrentForm() const {
    return currentForm;
}

void Tetramino::RotateTetra() {
    if (rotationCount > 1) {
        currentForm = (currentForm + 1) % rotationCount;
    }
}

int (*Tetramino::getShape())[4] {
    return possibleForms[currentForm];
}

void Tetramino::MoveTetraLeft(WINDOW *tetra, int x, int y) {
    wmove(tetra, x + 1, y);
}

void Tetramino::MoveTetraRight(WINDOW *tetra, int x, int y) {
    wmove(tetra, x - 1, y);
}

void Tetramino::MoveTetraDown(WINDOW *tetra, int x, int y) {
    wmove(tetra, x, y - 1);
}

void Tetramino::setX(int x) {
    Tetramino::x = x;
}

void Tetramino::setY(int y) {
    Tetramino::y = y;
}

void Tetramino::setShape(int newRotationCount, int (*newRotations)[4][4]) {
    rotationCount = newRotationCount;
    for (int r = 0; r < rotationCount; ++r) {
        for (int y = 0; y < 4; ++y) {
            for (int x = 0; x < 4; ++x) {
                possibleForms[r][y][x] = newRotations[r][y][x];
            }
        }
    }
}
