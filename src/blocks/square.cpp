#include "square.h"

Square::Square(BLOCK_COLOR color, int row, int col)
{
    this->color = color;
    this->row = row;
    this->col = col;
}

BLOCK_COLOR Square::getColor() { return color; }

int Square::getRow() { return row; }

int Square::getCol() { return col; }

void Square::setRow(int row) { this->row = row; }

void Square::setCol(int col) { this->col = col; }

void Square::bumpLeft() { col--; }

void Square::bumpRight() { col++; }

void Square::bumpDown() { row--; }

void Square::bumpUp() { row++; }

/*
    Rotate a Square s about a center, return a new copy of the square rotated 
*/
Square *Square::rotateSquareAboutCenter(Square *centerOfRotation, Square *s)
{
    int x = s->getCol() - centerOfRotation->getCol();
    int y = s->getRow() - centerOfRotation->getRow();

    return new Square(s->getColor(), (-1 * x) + centerOfRotation->getRow(), y + centerOfRotation->getCol());
}