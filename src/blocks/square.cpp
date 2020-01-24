#include "square.h"

Square::Square(BLOCK_COLOR color, int row, int col)
{
    color = color;
    row = row;
    col = col;
}

BLOCK_COLOR Square::getColor() { return color; };

int Square::getRow() { return row; };

int Square::getCol() { return col; };

int Square::setRow(int row) { this->row = row; };

int Square::setCol(int col) { this->col = col; };

void Square::bumpLeft() { col--; };

void Square::bumpRight() { col++; };