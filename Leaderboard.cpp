//
// Created by Matteo Santoro on 09/03/24.
//

#include "Leaderboard.h"
#include "fstream"
#include "MainMenu.h"

using namespace std;

Leaderboard::Leaderboard() {
    WINDOW *win = newwin(100, 100, 0, 0);
    nodelay(win, false);
    keypad(win, true);
    readLearboard(win);
}

void Leaderboard::writeScore(int score) {
    ofstream outputFile;
    outputFile.open("leaderboard.txt", ios::app);
    outputFile << score << "\n";
    outputFile.close();
}

void Leaderboard::readLearboard(WINDOW *board) {
    ifstream inputFile;
    inputFile.open("leaderboard.txt");
    char ch;
    while (!inputFile.eof()) {
        inputFile.get(ch);
        waddch(board, ch);
    }
    inputFile.close();
    waddstr(board, "press key up to return to main menu");
    int c = wgetch(board);
    while (c != KEY_UP) {
        c = wgetch(board);
    }
    werase(board);
    MainMenu s;

}
