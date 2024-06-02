#include <curses.h>
#include "Leaderboard.h"
#include "Startup_page.h"

#define BOARD_ROWS 18
#define BOARD_COLS 20

const char *getBoardRow();

int main() {
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    Leaderboard l;
    l.writeScore(15);

    Startup_page s;
    s.Page_Setup(BOARD_COLS,BOARD_ROWS);
    /*Game game(BOARD_COLS, BOARD_ROWS);
    game.run();*/
    return 0;
}



//