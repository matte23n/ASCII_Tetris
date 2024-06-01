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
    border_win = newwin(width + 2, height + 2, 0, 15);
    board_win = newwin(width, height, 1, 15);
    keypad(board_win, TRUE);
    keypad(stdscr, TRUE);
    //wtimeout(board_win, 300);
    nodelay(board_win, TRUE);
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
    wmove(board_win, y, 1);
    wclrtoeol(board_win);
}

void Board::addTetramino(Tetramino *t) {
    drawTetromino(t->getY(), t->getX(), *t);
}

Tetramino Board::spawnTetramino() {
    Line line(2, 0);
    currentTetramino = line;
    addTetramino(&line);
    return line;
}

bool Board::canPlaceTetramino(int x, int y) {
    int mx = 0, my = 0;
    getmaxyx(board_win, mx, my);
    my-=1;
    if (x > 0 && y < my) {
        return true;
    }
    if (y == my) {
        currentTetramino = spawnTetramino();
    }
    return false;
}

void Board::getNewCoordinates(int direction, int &x, int &y) {
    switch (direction) {
        case KEY_LEFT:
            x -= 1;
            break;
        case KEY_RIGHT:
            x += 1;
            break;
        case KEY_DOWN:
            y += 1;
            break;
        default:
            break;
    }
}

void Board::moveTetramino(int direction) {
    int newX = currentTetramino.getX();
    int newY = currentTetramino.getY();
    getNewCoordinates(direction, newX, newY);
    if (canPlaceTetramino(newX, newY)) {
        clearTetromino(currentTetramino.getY(), currentTetramino.getX(), currentTetramino);
        switch (direction) {
            case KEY_UP:
                clearTetromino(currentTetramino.getY()+1, currentTetramino.getX(), currentTetramino);
                currentTetramino.RotateTetra();
            case KEY_DOWN:
                drawTetromino(newY, newX, currentTetramino);
                currentTetramino.setY(newY);
                break;
            default:
                drawTetromino(newY, newX, currentTetramino);
                currentTetramino.setX(newX);
                break;
        }
    }
}

void Board::addAt(int x, int y, char ch[]) {
    mvwaddstr(board_win, y, x, ch);
}

void Board::drawTetromino(int startY, int startX, Tetramino &tetromino) {
    int (*shape)[4] = tetromino.getShape();
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            if (shape[y][x]) {
                mvwprintw(board_win, startY + y, startX + x, "X");
            }
        }
    }
    wrefresh(board_win);
}

void Board::clearTetromino(int startY, int startX, Tetramino &tetromino) {
    int (*shape)[4] = tetromino.getShape();
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            if (shape[y][x]) {
                std::cout << startY + y;
                std::cout << "SeeeS";
                std::cout << startX + x;
                mvwprintw(board_win, startY + y, startX + x, " ");
            }
        }
    }
    wrefresh(board_win);
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

