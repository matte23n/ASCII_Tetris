//
// Created by matti on 21/03/2024.
//

#include "Startup_page.h"
#include "curses.h"
#include "Leaderboard.h"
#include "iostream"
using namespace std;

    void Startup_page::Page_Setup(int x, int y, int *leaderboard) {
        initscr();
        WINDOW *win = newwin(x, y, 0, 0);
        wprintw(win, "TETRIS");
        keypad(win,true);
        wrefresh(win);
        while (true) {
            wrefresh(win);
            int c = wgetch(win);
            if (c == KEY_UP){
                wprintw(win,"ciao");
                delwin(win);
                endwin();
            } else if (c==1) {
                Leaderboard l;
                l.readLearboard(leaderboard);
            }
        }
    }

    void Startup_page::Game_Over(int x, int y, int *leaderboard){
        initscr();
        nocbreak();
        refresh();
        WINDOW *win = newwin(x, y, 50, 50);
        wprintw(win, "GAME OVER");
        wrefresh(win);
        while (true) {
            wrefresh(win);
            int c = wgetch(win);
            if(c==KEY_ENTER){
                Page_Setup(100,100, leaderboard);
            }
        }
    }