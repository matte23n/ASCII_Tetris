#include <curses.h>
#include "Leaderboard.h"
#include "Game.h"

#define BOARD_ROWS 18
#define BOARD_COLS 20

const char *getBoardRow();

int main() {
    initscr();
    noecho();
    cbreak();
    curs_set(0);

    Game game(BOARD_COLS, BOARD_ROWS);
    game.run();
    return 0;
}



//