//
// Created by Matteo Santoro on 01/06/24.
//

#ifndef ASCII_TETRIS_GAMEINFO_H
#define ASCII_TETRIS_GAMEINFO_H


#include <curses.h>

class GameInfo {
public:
    GameInfo();

    int getFullLines() const;

    void setFullLines(int fullLines);

    int getLevel() const;

    void setLevel(int level);

    int getScore() const;

    void setScore(int score);

    int getTime() const;

    void setTime(int time);

    void updateStatus();
    void waitRefresh();

private:
    WINDOW *gameInfo_win;
    int fullLines = 0;
    int level = 0;
    int score = 0;
    int time = 0;

};


#endif //ASCII_TETRIS_GAMEINFO_H
