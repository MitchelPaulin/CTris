#ifndef SQUARE_H
#define SQUARE_H

#include "../../include/constants.h"

class Square
{
private:
    BLOCK_COLOR color;
    int row, col;

public:
    Square(BLOCK_COLOR color, int row, int col);
    BLOCK_COLOR getColor();
    int getRow();
    int getCol();
    void setRow(int row);
    void setCol(int col);
    void bumpLeft();
    void bumpRight();
    void bumpDown();
    void bumpUp();
    static Square *rotateSquareAboutCenter(Square *centerOfRotation, Square *s);
};

#endif