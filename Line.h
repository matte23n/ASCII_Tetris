//
// Created by matti on 30/05/2024.
//

#ifndef TETRIS_LINE_H
#define TETRIS_LINE_H

#include "Tetramino.h"
#include "curses.h"


class Line : public Tetramino {
public:
    Line(int x, int y);
};


#endif //TETRIS_LINE_H
