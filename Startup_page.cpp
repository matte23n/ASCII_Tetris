//
// Created by matti on 21/03/2024.
//

#include "Startup_page.h"
#include "curses.h"
#include "Leaderboard.h"
#include "Game.h"
using namespace std;

    void Startup_page::Page_Setup(int x, int y) {
        initscr();
        WINDOW *win = newwin(60, 60, 0, 0);
        wprintw(win, "TETRIS");
        mvwaddstr(win,10,10,"press key up to start");
        mvwaddstr(win,15,10,"press key down to see leaderboard");
        keypad(win,true);
        wrefresh(win);
        while (true) {
            wrefresh(win);
            int c = wgetch(win);
            if (c == KEY_UP){
                wclear(win);
                wrefresh(win);
                delwin(win);
                Game game(x,y);
                game.run();
            } else if (c==1) {
                wclear(win);
                wrefresh(win);
                Leaderboard l;
                l.readLearboard(win);
            }
        }
    }

    void Startup_page::Game_Over(int x, int y){
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
                Page_Setup(100,100);
            }
        }
    }