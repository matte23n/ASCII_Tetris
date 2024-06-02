//
// Created by Matteo Santoro on 09/03/24.
//

#include "Leaderboard.h"
#include "fstream"
using namespace std;

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
        waddrawch(board,ch);
    }
    inputFile.close();
}
