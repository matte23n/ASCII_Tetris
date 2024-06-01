//
// Created by Matteo Santoro on 01/06/24.
//

#include "GameInfo.h"

GameInfo::GameInfo() {
    gameInfo_win = newwin(5, 10, 1, 1);
    wclear(gameInfo_win);
    wprintw(gameInfo_win, "Level: %d\n", level);
    wprintw(gameInfo_win, "Score: %d\n", score);
    wprintw(gameInfo_win, "Lines: %d\n", fullLines);
    wprintw(gameInfo_win, "Time: %d\n", time);
    wnoutrefresh(gameInfo_win);
}

int GameInfo::getFullLines() const {
    return fullLines;
}

void GameInfo::setFullLines(int fullLines) {
    GameInfo::fullLines = fullLines;
}

int GameInfo::getLevel() const {
    return level;
}

void GameInfo::setLevel(int level) {
    GameInfo::level = level;
}

int GameInfo::getScore() const {
    return score;
}

void GameInfo::setScore(int score) {
    GameInfo::score = score;
}

int GameInfo::getTime() const {
    return time;
}

void GameInfo::setTime(int time) {
    GameInfo::time = time;
}