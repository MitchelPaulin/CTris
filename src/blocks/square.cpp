#include "square.h"
#include <iostream>

Square::Square(BLOCK_COLOR color, int row, int col)
{
    this->color = color;
    this->row = row;
    this->col = col;
}

BLOCK_COLOR Square::getColor() { return color; }

int Square::getRow() { return row; }

int Square::getCol() { return col; }

int Square::setRow(int row) { this->row = row; }

int Square::setCol(int col) { this->col = col; }

void Square::bumpLeft() { col--; }

void Square::bumpRight() { col++; }

void Square::bumpDown() { row--; }