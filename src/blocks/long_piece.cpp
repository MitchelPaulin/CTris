#include "long_piece.h"

LongPiece::LongPiece()
{
    blocks.push_back(new Square(LongPiece::color, BOARD_HEIGHT - 1, BOARD_WIDTH - 5));
    blocks.push_back(new Square(LongPiece::color, BOARD_HEIGHT - 2, BOARD_WIDTH - 5));
    blocks.push_back(new Square(LongPiece::color, BOARD_HEIGHT - 3, BOARD_WIDTH - 5));
    blocks.push_back(new Square(LongPiece::color, BOARD_HEIGHT - 4, BOARD_WIDTH - 5));
}

LongPiece::~LongPiece() {}

void LongPiece::rotate()
{
}