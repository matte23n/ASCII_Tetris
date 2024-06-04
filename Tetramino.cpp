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

void Tetramino::RotateTetra() {
    if (rotationCount > 1) {
        currentForm = (currentForm + 1) % rotationCount;
    }
}

int (*Tetramino::getShape())[4] {
    return possibleForms[currentForm];
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
