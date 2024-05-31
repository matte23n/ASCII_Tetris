//
// Created by Matteo Santoro on 26/02/24.
//


#include "Board.h"

Board::Board() {
    border_win = newwin(0, 0, 0, 0);
    board_win = newwin(0, 0, 0, 0);
}

Board::Board(int width, int height) {
    border_win = newwin(width + 2, height + 2, 0, 0);
    board_win = newwin(width, height, 1, 1);
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
    addAt(t->getX(), t->getY(), t->getForm());
}

void Board::addAt(int x, int y, char *ch) {
    mvwaddstr(board_win, y, x, ch);
}

chtype Board::getInput() {
    return wgetch(board_win);
}

void Board::clear() {
    wclear(border_win);
    wclear(board_win);
    addBorder();
}

void Board::refresh() {
    wrefresh(board_win);
}

const char *Board::getBoardRow() {
    return "<!........!>";
}



