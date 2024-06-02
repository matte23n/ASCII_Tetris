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
    border_win = newwin(width, height, 0, 15);
    board_win = newwin(width - 2, height - 2, 1, 16);
    boardWidth = width;
    boardHeight = height;
    board = new int *[boardHeight];
    for (int i = 0; i < boardHeight; ++i) {
        board[i] = new int[boardWidth]();
    }
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

void Board::addTetramino(Tetramino *t) {
    drawTetromino(t->getY(), t->getX(), *t);
}

// Function to fix the tetromino on the board
void Board::fixTetromino(Tetramino &tetromino, int posY, int posX) {
    int (*shape)[4] = tetromino.getShape();
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            if (shape[y][x]) {
                board[posY + y][posX + x] = 1;
            }
        }
    }
}

Tetramino Board::spawnTetramino() {
    Line line(2, 0);
    currentTetramino = line;
    addTetramino(&line);
    return line;
}

bool Board::canMove(Tetramino &tetromino, int newY, int newX) {
    int size = 4;
    int (*shape)[4] = tetromino.getShape();
    for (int y = 0; y < size; ++y) {
        for (int x = 0; x < size; ++x) {
            if (shape[y][x]) {
                int newBoardY = newY + y;
                int newBoardX = newX + x;
                if (newBoardY < 0 || newBoardY >= boardHeight - 2 || newBoardX < 0 || newBoardX >= boardWidth - 2 ||
                    board[newBoardY][newBoardX]) {
                    return false;
                }
            }
        }
    }
    return true;
}

void Board::updateBoard(int prevY, int prevX, Tetramino &tetromino, int startY, int startX) {
    clearTetromino(prevY, prevX, tetromino);
    drawTetromino(startY, startX, tetromino);
}

bool Board::isLineFull(int line) {
    int mx = 0, my = 0;
    getmaxyx(board_win, mx, my);
    int j;
    for (j = 0; j < mx; j++) {
        if (board[line][j] == 0) {
            return false;
        }
    }
    return true;
}

void Board::clearLine(int line) {
    for (int x = 0; x < boardWidth; ++x) {
        board[line][x] = 0;
    }

    for (int y = line; y > 0; --y) {
        for (int x = 0; x < boardWidth; ++x) {
            board[y][x] = board[y - 1][x];
        }
    }

    for (int x = 0; x < boardWidth; ++x) {
        board[0][x] = 0;
    }
}

void Board::redrawBoard() {
    werase(board_win);
    for (int y = 0; y < boardHeight; ++y) {
        for (int x = 0; x < boardWidth; ++x) {
            if (board[y][x]) {
                mvwprintw(board_win, y + 1, x + 1, "X");
            }
        }
    }
    wrefresh(board_win);
}

void Board::moveTetramino(int direction) {
    int currentX = currentTetramino.getX();
    int prevX = currentTetramino.getX();
    int currentY = currentTetramino.getY();
    int prevY = currentTetramino.getY();

    if (direction == KEY_UP) {
        Tetramino temp = currentTetramino;
        temp.RotateTetra();
        if (canMove(temp, currentY, currentX)) {
            clearTetromino(currentY, currentX, currentTetramino); // Clear current tetromino before rotating
            currentTetramino = temp;
        }
    } else if (direction == KEY_LEFT && canMove(currentTetramino, currentY, currentX - 1)) {
        currentX--;
        currentTetramino.setX(currentX);
    }
    else if (direction == KEY_RIGHT && canMove(currentTetramino, currentY, currentX + 1)) {
        currentX++;
        currentTetramino.setX(currentX);
    }
    else if (direction == KEY_DOWN && canMove(currentTetramino, currentY + 1, currentX)) {
        currentY++;
        currentTetramino.setY(currentY);
    }

    updateBoard(prevY, prevX, currentTetramino, currentY, currentX);

    if (!canMove(currentTetramino, currentY + 1, currentX)) {
        fixTetromino(currentTetramino, currentY, currentX);

        for (int y = 0; y < boardHeight; ++y) {
            if (isLineFull(y)) {
                clearLine(y);
                redrawBoard();
            }
        }
        spawnTetramino();
    }
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
                mvwprintw(board_win, startY + y, startX + x, " ");
            }
        }
    }
    wrefresh(board_win);
}

int Board::getInput() {
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

