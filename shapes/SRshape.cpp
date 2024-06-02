//
// Created by mattia on 02/06/2024.
//

#include "SRshape.h"
SRshape::SRshape() : Tetramino() {
    int iShapeRotations[2][4][4] = {
            {
                    {0, 0, 0, 0},
                    {0, 1, 1, 0},
                    {0, 0, 1, 1},
                    {0, 0, 0, 0}
            },
            {
                    {0, 0, 0, 1},
                    {0, 0, 1, 1},
                    {0, 0, 1, 0},
                    {0, 0, 0, 0}
            },
    };
    setShape(2, iShapeRotations);
}