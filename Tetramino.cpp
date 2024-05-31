//
// Created by matti on 30/05/2024.
//

#include "Tetramino.h"
using namespace std;

Tetramino::Tetramino(int x, int y) {
    this->x = x;
    this->y = y;
}

int Tetramino::getX() {
    return x;
}

int Tetramino::getY() {
    return y;
}

char* Tetramino::getForm() {
    return form;
}


void Tetramino::MoveTetraLeft(WINDOW *tetra, int x, int y){
    wmove(tetra,x+1,y);
}

void Tetramino::MoveTetraRight(WINDOW *tetra, int x, int y) {
    wmove(tetra,x-1,y);
}

void Tetramino::MoveTetraDown(WINDOW *tetra, int x, int y) {
    wmove(tetra,x,y-1);
}

void Tetramino::RotateTetra(Tetramino tetra) {

}


