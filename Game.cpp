//
// Created by Matteo Santoro on 31/05/24.
//

#include "Game.h"
#include "shapes/Line.h"
#include "shapes/Square.h"
#include "shapes/TShape.h"
#include "shapes/LLshape.h"
#include "shapes/RLshape.h"
#include "shapes/SLshape.h"
#include "shapes/SRshape.h"
#include <chrono>
#include <cstdlib>
#include "GameOver.h"
#include "Leaderboard.h"

Game::Game(int width, int heigth) {
    board = Board(width, heigth);
    boardWidth = width;
    boardHeight = heigth;
    board.initialize();
    gameInfo = GameInfo();
    isGameOver = false;
    shapes[0] = new Line();
    shapes[1] = new Square();
    shapes[2] = new TShape();
    shapes[3] = new RLshape();
    shapes[4] = new LLshape();
    shapes[5] = new SLshape();
    shapes[6] = new SRshape();
}

void Game::spawnTetramino() {
    currentTetramino = shapes[rand() % 7];
    currentTetramino->setX((rand() % (boardWidth - 3)));
    currentTetramino->setY(0);
    // Check if the new tetromino can be placed
    if (!board.canMove(*currentTetramino, 0, currentTetramino->getX())) {
        // Game over
        setIsGameOver(true);
    } else {
        board.addTetramino(currentTetramino);
    }
}

void Game::run() {
    auto lastMove = std::chrono::steady_clock::now();
    auto lastInfoUpdate = std::chrono::steady_clock::now();
    double moveInterval = 1000;
    int infoInterval = 1000;
    srand(time(NULL));
    spawnTetramino();

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
        }
        moveInterval = 1000/(gameInfo.getLevel()*1.5);
    }
    Leaderboard::writeScore(gameInfo.getScore());
    werase(board.getBoardWIn());
    werase(gameInfo.getGameInfoWin());
    refresh();
    GameOver g;
}

void Game::processInput() {
    int direction = board.getInput();
    if (direction != -1) {
        int currentX = currentTetramino->getX();
        int prevX = currentTetramino->getX();
        int currentY = currentTetramino->getY();
        int prevY = currentTetramino->getY();

        if (direction == KEY_UP) {
            Tetramino temp = *currentTetramino;
            temp.RotateTetra();
            if (board.canMove(temp, currentY, currentX)) {
                board.clearTetromino(currentY, currentX,
                                     *currentTetramino); // Clear current tetromino before rotating
                *currentTetramino = temp;
            }
        } else if (direction == KEY_LEFT && board.canMove(*currentTetramino, currentY, currentX - 1)) {
            currentX--;
            currentTetramino->setX(currentX);
        } else if (direction == KEY_RIGHT && board.canMove(*currentTetramino, currentY, currentX + 1)) {
            currentX++;
            currentTetramino->setX(currentX);
        } else if (direction == KEY_DOWN && board.canMove(*currentTetramino, currentY + 1, currentX)) {
            currentY++;
            currentTetramino->setY(currentY);
        }

        board.updateBoard(prevY, prevX, *currentTetramino, currentY, currentX);

        if (!board.canMove(*currentTetramino, currentY + 1, currentX)) {
            board.fixTetromino(*currentTetramino, currentY, currentX);
            int fulllines =0;
            for (int y = 0; y < boardHeight; ++y) {
                if (board.isLineFull(y)) {
                    fulllines++;
                    gameInfo.setLevel(gameInfo.getLevel() + 1);
                    gameInfo.setFullLines(gameInfo.getFullLines() + 1);
                    board.clearLine(y);
                    board.redrawBoard();
                }
            }
            gameInfo.setScore(gameInfo.getScore() + (10*(fulllines*fulllines)));
            gameInfo.updateStatus();
            spawnTetramino();
        }
    }
}

void Game::makeTetraminoFall() {
    //update score, time ecc
    int currentX = currentTetramino->getX();
    int currentY = currentTetramino->getY();
    int prevY = currentTetramino->getY();
    if (board.canMove(*currentTetramino, currentY + 1, currentX)) {
        currentY++;
        currentTetramino->setY(currentY);

        board.updateBoard(prevY, currentTetramino->getX(), *currentTetramino, currentY,
                          currentTetramino->getX());
    } else {
        board.fixTetromino(*currentTetramino, currentY, currentX);
        int fulllines =0;
        for (int y = 0; y < boardHeight; ++y) {
            if (board.isLineFull(y)) {
                fulllines++;
                gameInfo.setLevel(gameInfo.getLevel() + 1);
                gameInfo.setFullLines(gameInfo.getFullLines() + 1);
                board.clearLine(y);
                board.redrawBoard();
            }
        }
        gameInfo.setScore(gameInfo.getScore() + (10*(fulllines*fulllines)));
        gameInfo.updateStatus();
        spawnTetramino();
    }

}

void Game::updateGameInfo() {
    gameInfo.setTime(gameInfo.getTime() + 1);
    gameInfo.updateStatus();
}

bool Game::isOver() {
    return isGameOver;
}

void Game::setIsGameOver(bool isGameOver) {
    Game::isGameOver = isGameOver;
}
