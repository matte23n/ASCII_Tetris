//
// Created by matti on 30/05/2024.
//

#ifndef TETRIS_TETRAMINO_H
#define TETRIS_TETRAMINO_H
#include "curses.h"


class Tetramino {
public :
    void MoveTetraLeft(WINDOW *tetra, int x, int y);

    void MoveTetraRight(WINDOW *tetra, int x, int y);

    void MoveTetraDown(WINDOW *tetra, int x, int y);

    void RotateTetra(Tetramino tetra);
};


#endif //TETRIS_TETRAMINO_H
