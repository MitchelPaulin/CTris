#include "square_piece.h"

SquarePiece::SquarePiece()
{
    blocks.push_back(new Square(SquarePiece::color, BOARD_HEIGHT - 3, BOARD_WIDTH - 6));
    blocks.push_back(new Square(SquarePiece::color, BOARD_HEIGHT - 3, BOARD_WIDTH - 5));
    blocks.push_back(new Square(SquarePiece::color, BOARD_HEIGHT - 4, BOARD_WIDTH - 6));
    blocks.push_back(new Square(SquarePiece::color, BOARD_HEIGHT - 4, BOARD_WIDTH - 5));
}

SquarePiece::~SquarePiece() {}

void SquarePiece::rotate()
{
}