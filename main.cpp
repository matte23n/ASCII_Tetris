#include <curses.h>
#include "Leaderboard.h"
#include "MainMenu.h"


const char *getBoardRow();

int main() {
    initscr();
    noecho();
    cbreak();
    curs_set(0);

    MainMenu s;
    return 0;
}



//