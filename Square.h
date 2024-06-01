//
// Created by matti on 30/05/2024.
//

#ifndef TETRIS_SQUARE_H
#define TETRIS_SQUARE_H
#include "Tetramino.h"
#include "curses.h"

class Square: public Tetramino {
public:
    Square(int x, int y);
};


#endif //TETRIS_SQUARE_H
