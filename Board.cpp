//
// Created by Matteo Santoro on 26/02/24.
//


#include <iostream>
#include "Board.h"
#include "Line.h"

Board::Board() {
    border_win = newwin(0, 0, 0, 0);
    board_win = newwin(0, 0, 0, 0);
}

Board::Board(int width, int height) {
    border_win = newwin(width + 2, height + 2, 0, 0);
    board_win = newwin(width, height, 1, 1);
    keypad(board_win, TRUE);
    keypad(stdscr, TRUE);
    wtimeout(board_win, 0);
    //box(board_win, 0, 0);
    //wrefresh(board_win);

    //wprintw(win, "%-15s %-10s\n", "FULL LINES: 0", getBoardRow());
    //wprintw(win, "%-15s %-10s\n", "LEVEL: 0", getBoardRow());
    //wprintw(win, "%-15s %-10s\n", "SCORE: 0", getBoardRow());
    //wprintw(win, "%-15s %-10s\n", "TIME: 0", getBoardRow());

    /*for (int i = 0; i < 20; i++) {
        wprintw(board_win, "%-15s %-10s\n", "", getBoardRow());
    }

    wprintw(board_win, "%-15s %-10s\n", "", "<!********!>");
    wprintw(board_win, "%-15s %-10s\n", "", R"(  \/\/\/\/  )");
*/

}

void Board::initialize() {
    clear();
    refresh();
    wrefresh(border_win);
}

void Board::addBorder() {
    box(border_win, 0, 0);
}

void Board::clearLine(int y) {
    wmove(board_win, y, 0);
    wclrtoeol(board_win);
}

void Board::addTetramino(Tetramino *t) {
    addAt(currentTetramino.getX(), currentTetramino.getY(), currentTetramino.getForm());
}

Tetramino Board::spawnTetramino() {
    Line line(2,0);
    addTetramino(&line);
    refresh();
    currentTetramino = line;
    return line;
}

bool Board::canPlaceTetramino(int x, int y) {
    int mx=0, my=0;
    getmaxyx(board_win, mx, my);
    std::cout << my;
    if (x > 0 and y < my) {
        return true;
    }
    if (y==my) {
        spawnTetramino();
    }
    return false;
}

void Board::getNewCoordinates(int direction, int &x, int &y) {
    switch (direction) {
        case KEY_LEFT:
            x -= 1;
        case KEY_RIGHT:
            x+= 1;
        case KEY_DOWN:
            y += 1;
    }
}

void Board::moveTetramino(int direction) {
    int newX = currentTetramino.getX();
    int newY = currentTetramino.getY();
    getNewCoordinates(direction, newX, newY);
    if (!canPlaceTetramino(newX, newY)) {
        return;
    }
    switch (direction) {
        case KEY_DOWN:
            clearLine(currentTetramino.getY());
            addAt(newX, newY, currentTetramino.getForm());
            currentTetramino.setY(newY);
            break;
        default:
            addAt(newX, currentTetramino.getY(), currentTetramino.getForm());
            currentTetramino.setX(newX);
            break;
    }
}

void Board::addAt(int x, int y, char *ch) {
    mvwaddstr(board_win, y, x, ch);
    refresh();
}

int Board::getInput() {
    return wgetch(board_win);
}

chtype Board::getCharAt(int x, int y) {
    return mvwinch(board_win, x, y);
}

void Board::clear() {
    wclear(border_win);
    wclear(board_win);
    addBorder();
}

void Board::refresh() {
    wrefresh(board_win);
}


