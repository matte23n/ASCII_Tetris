//
// Created by matti on 30/05/2024.
//

#include "Line.h"

Line::Line() : Tetramino() {
    int iShapeRotations[2][4][4] = {
            {
                    {0, 0, 0, 0},
                    {1, 1, 1, 1},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0}
            },
            {
                    {0, 0, 1, 0},
                    {0, 0, 1, 0},
                    {0, 0, 1, 0},
                    {0, 0, 1, 0}
            }
    };
    setShape(2, iShapeRotations);
}
