//
// Created by matti on 30/05/2024.
//

#ifndef TETRIS_TETRAMINO_H
#define TETRIS_TETRAMINO_H

#include "curses.h"

class Tetramino {
public :
    Tetramino();

    int getX();

    int getY();

    void setX(int x);

    void setY(int y);

    void RotateTetra();

    int (*getShape())[4];

    void setShape(int newRotationCount, int newRotations[4][4][4]);


protected:
    int x, y;
    int currentForm;
    int rotationCount;
    int possibleForms[4][4][4];
};


#endif //TETRIS_TETRAMINO_H
