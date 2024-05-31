#include <iostream>
#include <curses.h>
#include "Leaderboard.h"
#include "Board.h"
#include "Game.h"

#define BOARD_ROWS 30
#define BOARD_COLS 30

const char *getBoardRow();

int main() {
    initscr();
    noecho();

    Leaderboard l;
    l.writeScore(15);


    Game game(BOARD_COLS, BOARD_ROWS);
    //while (!game.isOver()) {
        game.processInput();


        game.updateStatus();


        //game.redraw();

        game.processInput();
    //}


    endwin();
    return 0;
}



//