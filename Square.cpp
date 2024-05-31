//
// Created by matti on 30/05/2024.
//

#include "Square.h"

void Square::CreateSquare(int x, int y) {
    initscr();
    nocbreak();
    WINDOW *square= newwin(2,2,x,y);
    wprintw(square,"[][]\n[][]");
    wrefresh(square);
}

void Square::HalfSquare(int x, int y) {
    initscr();
    nocbreak();
    WINDOW *halfsquare= newwin(1,2,x,y);
    wprintw(halfsquare,"[][]");
    wrefresh(halfsquare);
}
