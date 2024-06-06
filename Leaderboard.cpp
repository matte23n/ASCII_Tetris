//
// Created by Matteo Santoro on 09/03/24.
//
#include "Leaderboard.h"

using namespace std;
char *options[4] = {"Main menu", "Next Page", "Previous Page", "Quit"};

Leaderboard::Leaderboard() {
    int xMax, yMax;
    getmaxyx(stdscr, yMax, xMax);
    board = newwin(100, 100, 0, (xMax / 2));
    nodelay(board, false);
    keypad(board, true);
    readLeaderboard();
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
    inputFile.open("leaderboard.txt", ios::in);
    int number;
    while (!inputFile.eof()) {
        inputFile >> number;
        if (number) {
            i++;
        }
        number = 0;
    }
    inputFile.close();
    return i;
}

void Leaderboard::readLeaderboard() {
    ifstream inputFile;
    inputFile.open("leaderboard.txt");
    int highlight = 0;
    if (!inputFile.is_open()) {
        //File does not exist
        wprintw(board, "%s\n", "No games finished");
        setupMenuLoop(highlight, 0, 0, 0, {});
        return;
    }
    int totalScores = getLength();
    int numbers[totalScores];
    int j = 0;
    int currentPage = 0;
    int curScore = 0;
    int totalPages = (totalScores / SCORES_PER_PAGE) + (totalScores % SCORES_PER_PAGE > 0);
    while (!inputFile.eof()) {
        inputFile >> curScore;
        if (curScore) {
            numbers[j] = curScore;
            j++;
        }
        curScore = 0;
    }
    inputFile.close();
    for (int k = 0; k < totalScores - 1; ++k) {
        for (int l = 0; l < totalScores - 1; ++l) {
            if (numbers[l] < numbers[l + 1]) {
                int temp = numbers[l];
                numbers[l] = numbers[l + 1];
                numbers[l + 1] = temp;
            }
        }
    }
    printScores(currentPage, totalScores, totalPages, numbers);
    setupMenuLoop(highlight, currentPage, totalScores, totalPages, numbers);
    if (highlight == 0) {
        MainMenu s;
    } else {
        werase(board);
        refresh();
    }

}

void Leaderboard::setupMenuLoop(int &highlight, int currentPage, int totalScores, int totalPages, int numbers[]) {
    while (true) {
        for (int m = 0; m < 4; m++) {
            if (m == highlight) {
                wattron(board, A_REVERSE);
            }
            mvwprintw(board, m + 1, 20, options[m]);
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
                if (highlight > 3) {
                    highlight = 3;
                }
                break;
            default:
                break;
        }
        if (c == 10 && (highlight == 0 || highlight == 3)) {
            break;
        } else if (c == 10) {
            if (highlight == 1 && currentPage < totalPages - 1) {
                currentPage++;
                werase(board);
                printScores(currentPage, totalScores, totalPages, numbers);
            } else if (highlight == 2 && currentPage > 0) {
                currentPage--;
                werase(board);
                printScores(currentPage, totalScores, totalPages, numbers);
            }
        }
    }

}

void Leaderboard::printScores(int currentPage, int totalScores, int totalPages, int numbers[]) {
    for (int k = (SCORES_PER_PAGE * currentPage); k < ((SCORES_PER_PAGE * (currentPage + 1))); ++k) {
        if (k < totalScores) {
            wprintw(board, "%d\n", numbers[k]);
        }
    }
    wprintw(board, "%s%d\n", "Total scores: ", totalScores);
    wprintw(board, "%s%d/%d\n", "Page: ", currentPage + 1, totalPages);
}