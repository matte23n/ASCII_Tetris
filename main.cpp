#include <iostream>
#include <curses.h>
#include <print>
#include "Leaderboard.h"
#include "Board.h"
#include "Game.h"

#define BOARD_ROWS 30
#define BOARD_COLS 30

const char *getBoardRow();

int main() {
    initscr();
    noecho();
    curs_set(0);
    //cbreak();
    Leaderboard l;
    l.writeScore(15);


    Game game(BOARD_COLS, BOARD_ROWS);
    int i = 0;
    //while (!game.isOver()) {
    while (i < 100) {
        game.updateStatus();
        struct timespec ts;
        ts.tv_sec = 0;
        ts.tv_nsec = 100 * 1000 * 1000;
        nanosleep(&ts, NULL);
        game.processInput();
        //game.updateStatus();
        //game.redraw();
        //game.processInput();
        i++;
    }


    endwin();
    return 0;
}



//