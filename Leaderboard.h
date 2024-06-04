//
// Created by Matteo Santoro on 09/03/24.
//

#ifndef ASCII_TETRIS_LEADERBOARD_H
#define ASCII_TETRIS_LEADERBOARD_H
#include <iostream>
#include "curses.h"
#include "fstream"
#include "MainMenu.h"

class Leaderboard {
public:
    Leaderboard();
    static void writeScore(int score);

    void readLeaderboard(WINDOW *board);

    int getLength();
};


#endif //ASCII_TETRIS_LEADERBOARD_H
