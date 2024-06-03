//
// Created by Matteo Santoro on 09/03/24.
//

#include "Leaderboard.h"
#include "fstream"
#include "MainMenu.h"

using namespace std;
char *options[2]={"Main menu", "Quit"};

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
    int highlight=0;
    while (true) {
        for (int i = 0; i < 2; i++) {
            if (i == highlight) {
                wattron(board, A_REVERSE);
            }
            mvwprintw(board, i + 1, 10, options[i]);
            wattroff(board, A_REVERSE);
        }
        int c = wgetch(board);
        switch (c) {
            case KEY_UP:
                highlight--;
                if (highlight < 0) {
                    highlight = 0;
                }
                break;
            case KEY_DOWN:
                highlight++;
                if (highlight > 1) {
                    highlight = 1;
                }
                break;
            default:
                break;
        }
        if (c == 10) {
            break;
        }
    }
    if(highlight==0){
        MainMenu s;
    }else{
        werase(board);
        refresh();
    }

}
