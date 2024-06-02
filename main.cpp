#include <curses.h>
#include "Leaderboard.h"
#include "Game.h"

#define BOARD_ROWS 30
#define BOARD_COLS 30

const char *getBoardRow();

int main() {
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    Leaderboard l;
    l.writeScore(15);


    Game game(BOARD_COLS, BOARD_ROWS);
    game.run();
    return 0;
}



//