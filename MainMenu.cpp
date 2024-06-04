//
// Created by matti on 21/03/2024.
//

#include "MainMenu.h"
#include "curses.h"
#include "Leaderboard.h"
#include "Game.h"

using namespace std;
char *choices[3] = {"New Game", "View Leaderboard", "Quit"};

MainMenu::MainMenu() {
    initscr();
    int xMax, yMax;
    getmaxyx(stdscr, yMax, xMax);
    WINDOW *win = newwin(60, 60, 0, (xMax/2));
    nodelay(win, false);
    keypad(win, true);
    wrefresh(win);
    int highlight = 0;
    while (true) {
        for (int i = 0; i < 3; i++) {
            if (i == highlight) {
                wattron(win, A_REVERSE);
            }
            mvwprintw(win, i + 1, 0, choices[i]);
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
                if (highlight > 2) {
                    highlight = 2;
                }
                break;
            default:
                break;
        }
        if (c == 10) {
            break;
        }
    }
    werase(win);
    wclear(win);
    wrefresh(win);
    if (highlight == 0) {
        Game game(18, 20);
        game.run();
    } else if (highlight == 1) {
        Leaderboard l;
    } else {
        endwin();
    }
}

