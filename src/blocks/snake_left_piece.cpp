#include "snake_left_piece.h"

SnakeLeftPiece::SnakeLeftPiece()
{
    blocks.push_back(new Square(SnakeLeftPiece::color, BOARD_HEIGHT - 3, BOARD_WIDTH - 6));
    blocks.push_back(new Square(SnakeLeftPiece::color, BOARD_HEIGHT - 3, BOARD_WIDTH - 5));
    blocks.push_back(new Square(SnakeLeftPiece::color, BOARD_HEIGHT - 4, BOARD_WIDTH - 5));
    blocks.push_back(new Square(SnakeLeftPiece::color, BOARD_HEIGHT - 4, BOARD_WIDTH - 4));
}

SnakeLeftPiece::~SnakeLeftPiece() {}

void SnakeLeftPiece::rotate()
{
}