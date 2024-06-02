#include <curses.h>
#include "Leaderboard.h"
#include "Game.h"
#include <chrono>

#define BOARD_ROWS 30
#define BOARD_COLS 30

const char *getBoardRow();

int main() {
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    Leaderboard l;
    l.writeScore(15);


    Game game(BOARD_COLS, BOARD_ROWS);
    int i = 0;

    auto lastMove = std::chrono::steady_clock::now();
    auto lastInfoUpdate = std::chrono::steady_clock::now();
    int moveInterval = 150;  // Interval in milliseconds
    int infoInterval = 1000;  // Interval in millisecond
    int seconds = 0;

    while (!game.isOver()) {

        auto now = std::chrono::steady_clock::now();

        game.processInput();

        // Move tetromino every moveInterval milliseconds
        if (std::chrono::duration_cast<std::chrono::milliseconds>(now - lastMove).count() >= moveInterval) {
            game.updateStatus();
            lastMove = now;  // Update the last move time
        }

        // Update game info every infoInterval milliseconds
        if (std::chrono::duration_cast<std::chrono::milliseconds>(now - lastInfoUpdate).count() >= infoInterval) {
            game.updateGameInfo();
            lastInfoUpdate = now;
            seconds++;
        }

        if (seconds == 45) {
            game.setIsGameOver(true);
        }
        i++;
    }
    endwin();
    return 0;
}



//