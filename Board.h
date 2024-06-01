//
// Created by Matteo Santoro on 26/02/24.
//

#ifndef ASCII_TETRIS_BOARD_H
#define ASCII_TETRIS_BOARD_H
#include <curses.h>

#include "Tetramino.h"

class Board {
public:
    Board();
    Board(int width, int height);

    void initialize();
    void addBorder();
    void clearLine(int y);
    void addTetramino(Tetramino* t);
    void moveTetramino(int direction);
    void addAt(int x, int y, char* ch);
    int getInput();
    chtype getCharAt(int x, int y);
    void clear();

    void refresh();

    Tetramino spawnTetramino();

private:
    WINDOW *board_win;
    WINDOW *border_win;
    Tetramino currentTetramino;

    bool canPlaceTetramino(int x, int y);

    void getNewCoordinates(int direction, int& x, int& y);

};


#endif //ASCII_TETRIS_BOARD_H
