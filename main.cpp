#include <curses.h>
#include "Leaderboard.h"
#include "Startup_page.h"


const char *getBoardRow();

int main() {
    initscr();
    noecho();
    cbreak();
    curs_set(0);

    Startup_page s;
    s.Page_Setup();
    /*Game game(BOARD_COLS, BOARD_ROWS);
    game.run();*/
    return 0;
}



//