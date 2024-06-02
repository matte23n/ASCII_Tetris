//
// Created by matti on 21/03/2024.
//

#include "Startup_page.h"
#include "curses.h"
#include "Leaderboard.h"
#include "Game.h"
using namespace std;

    void Startup_page::Page_Setup() {
        initscr();
        WINDOW *win = newwin(60, 60, 0, 0);
        nodelay(win,false);
        wprintw(win, "TETRIS");
        mvwaddstr(win,10,10,"press key up to start");
        mvwaddstr(win,15,10,"press key down to see leaderboard");
        mvwaddstr(win,20,10,"press key left to end session");
        keypad(win,true);
        wrefresh(win);
        int c = wgetch(win);
        while(c!=KEY_UP && c!=KEY_DOWN && c!=KEY_LEFT) {
            c= wgetch(win);
        }
            if (c == KEY_UP) {
                wclear(win);
                wrefresh(win);
                werase(win);
                Game game(18, 20);
                game.run();
            } else if (c == KEY_DOWN) {
                wclear(win);
                wrefresh(win);
                Leaderboard l;
            }else if(c==KEY_LEFT){
                endwin();
            }
    }

