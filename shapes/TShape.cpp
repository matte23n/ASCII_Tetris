//
// Created by Matteo Santoro on 02/06/24.
//

#include "TShape.h"
TShape::TShape() : Tetramino() {
    int iShapeRotations[4][4][4] = {
            {
                    {0, 0, 1, 0},
                    {0, 1, 1, 1},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0}
            },
            {
                    {0, 0, 1, 0},
                    {0, 0, 1, 1},
                    {0, 0, 1, 0},
                    {0, 0, 0, 0}
            },
            {
                    {0, 0, 0, 0},
                    {0, 1, 1, 1},
                    {0, 0, 1, 0},
                    {0, 0, 0, 0}
            },
            {
                    {0, 0, 1, 0},
                    {0, 1, 1, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 0}
            }
    };
    setShape(4, iShapeRotations);
}