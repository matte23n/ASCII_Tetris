#include <iostream>
#include <ncurses.h>
#include "Leaderboard.h"

const char *getBoardRow();

int main() {
    initscr();

    Leaderboard l;
    l.writeScore(15);
    WINDOW *win = newwin(30,30,0,0);
    refresh();

    wprintw(win,"%-15s %-10s\n", "FULL LINES: 0", getBoardRow());
    wprintw(win,"%-15s %-10s\n", "LEVEL: 0", getBoardRow());
    wprintw(win,"%-15s %-10s\n", "SCORE: 0", getBoardRow());
    wprintw(win,"%-15s %-10s\n", "TIME: 0", getBoardRow());

    for(int i = 0;i<20;i++) {
        wprintw(win,"%-15s %-10s\n", "", getBoardRow());
    }

    wprintw(win,"%-15s %-10s\n", "", "<!********!>");
    wprintw(win,"%-15s %-10s\n", "", R"(  \/\/\/\/  )");

    wrefresh(win);

    //keypad(win, true);

    wgetch(win);

    endwin();
    return 0;
}

const char* getBoardRow() {
    return "<!........!>";
}