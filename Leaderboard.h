//
// Created by Matteo Santoro on 09/03/24.
//

#ifndef ASCII_TETRIS_LEADERBOARD_H
#define ASCII_TETRIS_LEADERBOARD_H

#include <iostream>
#include "curses.h"
#include "fstream"
#include "MainMenu.h"

#define SCORES_PER_PAGE 10


class Leaderboard {
public:
    Leaderboard();

    static void writeScore(int score);

    void readLeaderboard();

    int getLength();

private:
    WINDOW *board;

    void setupMenuLoop(int &highlight, int currentPage, int totalScores, int totalPages, int numbers[]);

    void printScores(int currentPage, int totalScores, int totalPages, int numbers[]);
};


#endif //ASCII_TETRIS_LEADERBOARD_H
