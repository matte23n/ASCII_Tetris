//
// Created by matti on 30/05/2024.
//

#include "Square.h"
Square::Square() : Tetramino() {
    int iShapeRotations[1][4][4] = {
            {
                    {0, 0, 0, 0},
                    {0, 1, 1, 0},
                    {0, 1, 1, 0},
                    {0, 0, 0, 0}
            },
    };
    setShape(1, iShapeRotations);
}
