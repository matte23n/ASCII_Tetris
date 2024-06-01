//
// Created by Matteo Santoro on 31/05/24.
//

#include <print>
#include <iostream>
#include "Game.h"
#include "Line.h"

Game::Game(int width, int heigth) {
    board = Board(width, heigth);
    board.initialize();
    gameInfo = GameInfo();
    isGameOver = false;
    board.spawnTetramino();
}


void Game::processInput() {
    int input = board.getInput();
    if (input != -1) {
        board.moveTetramino(input);
    }
}

void Game::updateStatus() {
    //update score, time ecc
    board.moveTetramino(KEY_DOWN);
    //gameInfo.waitRefresh();
    //sleep(2);
    /*Line line(4,7);
    board.addTetramino(&line);
    board.refresh();
    sleep(1);
    board.clearLine(line.getY());
    Line line1(4,8);
    board.addTetramino(&line1);
    board.refresh();
    sleep(1);
    board.clearLine(line1.getY());
    Line line2(4,9);
    board.addTetramino(&line2);
    board.refresh();
    sleep(1);*/
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
