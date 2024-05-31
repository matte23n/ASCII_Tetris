//
// Created by Matteo Santoro on 31/05/24.
//

#ifndef ASCII_TETRIS_GAME_H
#define ASCII_TETRIS_GAME_H

#include <curses.h>
#include "Board.h"

class Game {
public:
    Game(int width, int height);
    void processInput();
    void redraw();
    void updateStatus();
    bool isOver();

private:
    Board board;
    bool isGameOver;
};


#endif //ASCII_TETRIS_GAME_H
