//an abstraction of one tetris square
#ifndef SQUARE_H
#define SQAURE_H

#include "../../include/constants.h"

class Square
{
private:
    BLOCK_COLOR color;
    int row, col;

public:
    Square(BLOCK_COLOR color, int row, int col)
    {
        this->color = color;
        this->row = row;
        this->col = col;
    }
    BLOCK_COLOR getColor() { return color; };
    int getRow() { return row; };
    int getCol() { return col; };
    int setRow(int row) { this->row = row; };
    int setCol(int col) { this->col = col; };
    void bumpLeft() { col--; };
    void bumpRight() { col++; };
};

#endif