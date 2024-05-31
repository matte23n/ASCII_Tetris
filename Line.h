//
// Created by matti on 30/05/2024.
//

#ifndef TETRIS_LINE_H
#define TETRIS_LINE_H
#include "Tetramino.h"
#include "curses.h"


class Line : public Tetramino{
public:
    WINDOW* CreateLineH(int x, int y);

    void CreateLineV(int x, int y);

    void Line1x1(int x, int y);

    void Line1x2(int x, int y);

    void Line1x3(int x, int y);

};


#endif //TETRIS_LINE_H
