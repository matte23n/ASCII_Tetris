//
// Created by mattia on 02/06/2024.
//

#include "GameOver.h"

char *scelte[2] = {"Main menu", "Quit"};

GameOver::GameOver() {
    initscr();
    int xMax, yMax;
    getmaxyx(stdscr, yMax, xMax);
    WINDOW *win = newwin(50, 50, 0, (xMax/2));
    keypad(win, true);
    wprintw(win, "GAME OVER");
    wrefresh(win);
    int highlight = 0;
    while (true) {
        for (int i = 0; i < 2; i++) {
            if (i == highlight) {
                wattron(win, A_REVERSE);
            }
            mvwprintw(win, i + 3, 0, scelte[i]);
            wattroff(win, A_REVERSE);
        }
        int c = wgetch(win);
        switch (c) {
            case KEY_UP:
                highlight--;
                if (highlight < 0) {
                    highlight = 0;
                }
                break;
            case KEY_DOWN:
                highlight++;
                if (highlight > 1) {
                    highlight = 1;
                }
                break;
            default:
                break;
        }
        if (c == 10) {
            break;
        }
    }
    if (highlight == 0) {
        MainMenu s;
    } else {
        werase(win);
        refresh();
    }
}