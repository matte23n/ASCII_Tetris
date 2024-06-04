//
// Created by Matteo Santoro on 09/03/24.
//
#include "Leaderboard.h"

using namespace std;
char *options[2] = {"Main menu", "Quit"};

Leaderboard::Leaderboard() {
    int xMax, yMax;
    getmaxyx(stdscr, yMax, xMax);
    WINDOW *win = newwin(100, 100, 0, (xMax/2));
    nodelay(win, false);
    keypad(win, true);
    readLeaderboard(win);
}

void Leaderboard::writeScore(int score) {
    ofstream outputFile;
    outputFile.open("leaderboard.txt", ios::app);
    outputFile << score << "\n";
    outputFile.close();
}

int Leaderboard::getLength() {
    int i = 0;
    ifstream inputFile;
    inputFile.open("leaderboard.txt");
    int number;
    while (!inputFile.eof()) {
        inputFile >> number;
        i++;
    }
    inputFile.close();
    return i;
}

void Leaderboard::readLeaderboard(WINDOW *board) {
    int i = getLength();
    ifstream inputFile;
    inputFile.open("leaderboard.txt");
    int numbers[i];
    int j = 0;
    while (!inputFile.eof()) {
        inputFile >> numbers[j];
        j++;
    }
    inputFile.close();
    for (int k = 0; k < i - 1; ++k) {
        for (int l = 0; l < i - 1; ++l) {
            if (numbers[l] < numbers[l + 1]) {
                int temp = numbers[l];
                numbers[l] = numbers[l + 1];
                numbers[l + 1] = temp;
            }
        }
    }
    for (int k = 0; k < j; ++k) {
        wprintw(board, "%d\n", numbers[k]);
    }
    int highlight = 0;
    while (true) {
        for (int m = 0; m < 2; m++) {
            if (m == highlight) {
                wattron(board, A_REVERSE);
            }
            mvwprintw(board, m + 1, 10, options[m]);
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
    if (highlight == 0) {
        MainMenu s;
    } else {
        werase(board);
        refresh();
    }

}
