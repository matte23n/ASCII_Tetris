//
// Created by mattia on 02/06/2024.
//

#include "GameOver.h"

GameOver::GameOver() {
    initscr();
    WINDOW *win = newwin(50, 50, 0, 0);
    keypad(win, true);
    nodelay(win, false);
    wprintw(win, "GAME OVER");
    mvwaddstr(win, 10, 10, "press key up to return to main menu");
    wrefresh(win);
    int c = wgetch(win);
    while (c != KEY_UP) {
        c = wgetch(win);
    }
    werase(win);
    refresh();
    MainMenu s;
}