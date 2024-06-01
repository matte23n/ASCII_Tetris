//
// Created by matti on 30/05/2024.
//

#ifndef TETRIS_TETRAMINO_H
#define TETRIS_TETRAMINO_H
#include "curses.h"

enum Direction {
    up,
    left,
    right,
    rotate
};

class Tetramino {
public :
    Tetramino();
    Tetramino(int x, int y);

    int getX();
    int getY();

    void setX(int x);
    void setY(int y);
    void setForm(char *form);

    char* getForm();
    void MoveTetraLeft(WINDOW *tetra, int x, int y);

    void MoveTetraRight(WINDOW *tetra, int x, int y);

    void MoveTetraDown(WINDOW *tetra, int x, int y);

    void RotateTetra(Tetramino tetra);
protected:
    int x,y;
    char* form;
};


#endif //TETRIS_TETRAMINO_H
