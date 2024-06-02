//
// Created by mattia on 02/06/2024.
//

#include "GameOver.h"
void GameOver::Game_Over(){
    initscr();
    WINDOW *win = newwin(50, 50, 0, 0);
    keypad(win,true);
    nodelay(win,false);
    wprintw(win, "GAME OVER");
    waddstr(win,"press key up to return to main menu");
    wrefresh(win);
    int c = wgetch(win);
    while(c!=KEY_UP) {
        c=wgetch(win);
    }
    werase(win);
    refresh();
    Startup_page s;
    s.Page_Setup();
}