//
// Created by Matteo Santoro on 31/05/24.
//

#ifndef ASCII_TETRIS_GAME_H
#define ASCII_TETRIS_GAME_H

#include <curses.h>
#include "Board.h"
#include "GameInfo.h"

class Game {
public:
    Game(int width, int height);
    void processInput();
    void updateGameInfo();
    void makeTetraminoFall();
    bool isOver();

    void setIsGameOver(bool isGameOver);

    void run();

private:
    Board board;
    bool isGameOver;
    GameInfo gameInfo;
    int boardHeight;
    int boardWidth;
    Tetramino *shapes[7];
    Tetramino *currentTetramino;
    void spawnTetramino();
};


#endif //ASCII_TETRIS_GAME_H
