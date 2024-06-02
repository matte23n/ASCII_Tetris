//
// Created by Matteo Santoro on 31/05/24.
//

#include "Game.h"
#include "Line.h"
#include <chrono>

Game::Game(int width, int heigth) {
    board = Board(width, heigth);
    boardHeight = heigth;
    boardWidth = width;
    board.initialize();
    gameInfo = GameInfo();
    isGameOver = false;
    board.spawnTetramino();
}

void Game::run() {
    int i = 0;

    auto lastMove = std::chrono::steady_clock::now();
    auto lastInfoUpdate = std::chrono::steady_clock::now();
    int moveInterval = 600;  // Interval in milliseconds
    int infoInterval = 1000;  // Interval in millisecond
    int seconds = 0;

    while (!isOver()) {

        auto now = std::chrono::steady_clock::now();

        processInput();

        // Move tetromino every moveInterval milliseconds
        if (std::chrono::duration_cast<std::chrono::milliseconds>(now - lastMove).count() >= moveInterval) {
            makeTetraminoFall();
            lastMove = now;  // Update the last move time
        }

        // Update game info every infoInterval milliseconds
        if (std::chrono::duration_cast<std::chrono::milliseconds>(now - lastInfoUpdate).count() >= infoInterval) {
            updateGameInfo();
            lastInfoUpdate = now;
            seconds++;
        }

        if (seconds == 300) {
            setIsGameOver(true);
        }
        i++;
        moveInterval = 600/gameInfo.getLevel();
    }
    endwin();
}

void Game::processInput() {
    int direction = board.getInput();
    if (direction != -1) {
        int currentX = board.currentTetramino.getX();
        int prevX = board.currentTetramino.getX();
        int currentY = board.currentTetramino.getY();
        int prevY = board.currentTetramino.getY();

        if (direction == KEY_UP) {
            Tetramino temp = board.currentTetramino;
            temp.RotateTetra();
            if (board.canMove(temp, currentY, currentX)) {
                board.clearTetromino(currentY, currentX,
                                     board.currentTetramino); // Clear current tetromino before rotating
                board.currentTetramino = temp;
            }
        } else if (direction == KEY_LEFT && board.canMove(board.currentTetramino, currentY, currentX - 1)) {
            currentX--;
            board.currentTetramino.setX(currentX);
        } else if (direction == KEY_RIGHT && board.canMove(board.currentTetramino, currentY, currentX + 1)) {
            currentX++;
            board.currentTetramino.setX(currentX);
        } else if (direction == KEY_DOWN && board.canMove(board.currentTetramino, currentY + 1, currentX)) {
            currentY++;
            board.currentTetramino.setY(currentY);
        }

        board.updateBoard(prevY, prevX, board.currentTetramino, currentY, currentX);

        if (!board.canMove(board.currentTetramino, currentY + 1, currentX)) {
            board.fixTetromino(board.currentTetramino, currentY, currentX);

            for (int y = 0; y < boardHeight; ++y) {
                if (board.isLineFull(y)) {
                    board.clearLine(y);
                    board.redrawBoard();
                }
            }
            board.spawnTetramino();
        }
    }
}

void Game::makeTetraminoFall() {
    //update score, time ecc
    int currentX = board.currentTetramino.getX();
    int currentY = board.currentTetramino.getY();
    int prevY = board.currentTetramino.getY();
    if (board.canMove(board.currentTetramino, currentY + 1, currentX)) {
        currentY++;
        board.currentTetramino.setY(currentY);

        board.updateBoard(prevY, board.currentTetramino.getX(), board.currentTetramino, currentY,
                          board.currentTetramino.getX());
    } else {
        board.fixTetromino(board.currentTetramino, currentY, currentX);

        for (int y = 0; y < boardHeight; ++y) {
            if (board.isLineFull(y)) {
                gameInfo.setScore(gameInfo.getScore() + 10);
                gameInfo.setLevel(gameInfo.getLevel() + 1);
                gameInfo.setFullLines(gameInfo.getFullLines() + 1);
                gameInfo.updateStatus();
                board.clearLine(y);
                board.redrawBoard();
            }
        }
        board.spawnTetramino();
    }

}

void Game::updateGameInfo() {
    //board.refresh();
    gameInfo.setTime(gameInfo.getTime() + 1);
    gameInfo.updateStatus();
}

bool Game::isOver() {
    return isGameOver;
}

void Game::setIsGameOver(bool isGameOver) {
    Game::isGameOver = isGameOver;
}
