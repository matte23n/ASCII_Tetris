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
    void addTetramino(Tetramino* t);
    void fixTetromino(Tetramino &tetromino, int posY, int posX);
    void moveTetramino(int direction);
    int getInput();
    void drawTetromino(int startY, int startX, Tetramino &tetromino);
    void clearTetromino(int startY, int startX, Tetramino &tetromino);
    void clear();

    void refresh();

    Tetramino spawnTetramino();

private:
    WINDOW *board_win;
    int boardHeight = 0;
    int boardWidth = 0;
    int **board;

    Tetramino currentTetramino;

    bool isLineFull(int line);
    void clearLine(int line);
    void redrawBoard();

    void updateBoard(int prevY, int prevX, Tetramino &tetromino, int startY, int startX);

    bool canMove(Tetramino &tetromino, int newY, int newX);
};


#endif //ASCII_TETRIS_BOARD_H
