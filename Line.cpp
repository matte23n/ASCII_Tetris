//
// Created by matti on 30/05/2024.
//

#include "Line.h"

Line::Line(int x, int y) : Tetramino(x, y) {
    form = "[][][][]";
}

WINDOW* Line::CreateLineH(int x, int y) {
    initscr();
    nocbreak();
    WINDOW *line= newwin(1,4,x,y);
    wprintw(line,"[][][][]");
    wrefresh(line);
    return line;
}

void Line::CreateLineV(int x, int y) {
    initscr();
    nocbreak();
    WINDOW *line= newwin(4,1,x,y);
    wprintw(line,"[]\n[]\n[]\n[]");
    wrefresh(line);
}

void Line::Line1x1(int x, int y) {
    initscr();
    nocbreak();
    WINDOW *line= newwin(1,1,x,y);
    wprintw(line,"[]");
    wrefresh(line);
}

void Line::Line1x2(int x, int y) {
    initscr();
    nocbreak();
    WINDOW *line= newwin(2,1,x,y);
    wprintw(line,"[]\n[]");
    wrefresh(line);
}

void Line::Line1x3(int x, int y) {
    initscr();
    nocbreak();
    WINDOW *line= newwin(3,1,x,y);
    wprintw(line,"[]\n[]\n[]");
    wrefresh(line);
}
