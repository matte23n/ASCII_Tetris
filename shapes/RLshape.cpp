//
// Created by mattia on 02/06/2024.
//

#include "RLshape.h"
RLshape::RLshape() : Tetramino() {
    int iShapeRotations[4][4][4] = {
            {
                    {0, 0, 1, 0},
                    {0, 0, 1, 0},
                    {0, 0, 1, 1},
                    {0, 0, 0, 0}
            },
            {
                    {0, 0, 0, 0},
                    {0, 1, 1, 1},
                    {0, 1, 0, 0},
                    {0, 0, 0, 0}
            },
            {
                    {0, 1, 1, 0},
                    {0, 0, 1, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 0}
            },
            {
                    {0, 0, 0, 1},
                    {0, 1, 1, 1},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0}
            }
    };
    setShape(4, iShapeRotations);
}