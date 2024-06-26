//
// Created by Matteo Santoro on 01/06/24.
//

#include "GameInfo.h"

GameInfo::GameInfo() {
    int xMax, yMax;
    getmaxyx(stdscr, yMax, xMax);
    gameInfo_win = newwin(5, 10, 1, (xMax/2) - 14);
    wclear(gameInfo_win);
    wprintw(gameInfo_win, "Level: %d\n", level);
    wprintw(gameInfo_win, "Score: %d\n", score);
    wprintw(gameInfo_win, "Lines: %d\n", fullLines);
    wprintw(gameInfo_win, "Time: %d\n", time);
    wnoutrefresh(gameInfo_win);
    nodelay(gameInfo_win, TRUE);
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

void GameInfo::updateStatus() {
    wgetch(gameInfo_win);
    mvwprintw(gameInfo_win, 0, 0, "Level: %d", level);
    mvwprintw(gameInfo_win, 1, 0, "Score: %d", score);
    mvwprintw(gameInfo_win, 2, 0, "Lines: %d", fullLines);
    int minutes = time / 60;
    int secs = (time - (minutes) * 60);
    mvwprintw(gameInfo_win, 3, 0, "Time: %d:%02d", minutes, secs);
    wrefresh(gameInfo_win);
}

WINDOW *GameInfo::getGameInfoWin() const {
    return gameInfo_win;
}
