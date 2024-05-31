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
    void addAt(int x, int y, char* ch);
    chtype getInput();
    void clear();

    void refresh();
private:
    WINDOW *board_win;
    WINDOW *border_win;
    const char* getBoardRow();
};


#endif //ASCII_TETRIS_BOARD_H
