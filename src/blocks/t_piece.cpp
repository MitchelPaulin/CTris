#include "t_piece.h"

TPiece::TPiece()
{
    blocks.push_back(new Square(TPiece::color, BOARD_HEIGHT - 3, BOARD_WIDTH - 6));
    blocks.push_back(new Square(TPiece::color, BOARD_HEIGHT - 3, BOARD_WIDTH - 5));
    blocks.push_back(new Square(TPiece::color, BOARD_HEIGHT - 3, BOARD_WIDTH - 4));
    blocks.push_back(new Square(TPiece::color, BOARD_HEIGHT - 4, BOARD_WIDTH - 5));
}

TPiece::~TPiece() {}

void TPiece::rotate()
{
}