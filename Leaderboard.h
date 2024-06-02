//
// Created by Matteo Santoro on 09/03/24.
//

#ifndef ASCII_TETRIS_LEADERBOARD_H
#define ASCII_TETRIS_LEADERBOARD_H
#include "curses.h"

class Leaderboard {
public:
    Leaderboard();
    static void writeScore(int score);

    void readLearboard(WINDOW *board);
};


#endif //ASCII_TETRIS_LEADERBOARD_H
