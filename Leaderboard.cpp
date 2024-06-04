//
// Created by Matteo Santoro on 09/03/24.
//
#include "Leaderboard.h"

using namespace std;
char *opciones[2]={"main menu","quit"};

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

int Leaderboard::getLenght(){
    int i=0;
    ifstream inputFile;
    inputFile.open("leaderboard.txt");
    string line;
    while (!inputFile.eof()){
        getline(inputFile, line);
        i++;
    }
    inputFile.close();
    return i;
}

void Leaderboard::readLearboard(WINDOW *board) {
    int i=getLenght();
    string line;
    ifstream inputFile;
    inputFile.open("leaderboard.txt");
    string ch[i];
    int j=0;
    while (getline(inputFile,line)) {
        ch[j]=line;
        j++;
    }
    string temp;
    for (int k = 0; k < i-1; ++k) {
        for (int l = 0; l < i-1; ++l) {
            if(ch[l].compare(ch[l+1])<0){
                temp=ch[l];
                ch[l]=ch[l+1];
                ch[l+1]=temp;
            }
        }
    }
    for (int k = 0; k < i; ++k) {
        waddstr(board,ch[k].c_str());
        waddstr(board,"\n");
    }
    inputFile.close();
    int highlight=0;
    while (true) {
        for (int i = 0; i < 2; i++) {
            if (i == highlight) {
                wattron(board, A_REVERSE);
            }
            mvwprintw(board, i + 1, 10, opciones[i]);
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
