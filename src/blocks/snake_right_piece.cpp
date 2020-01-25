#include "snake_right_piece.h"

SnakeRightPiece::SnakeRightPiece()
{
    blocks.push_back(new Square(SnakeRightPiece::color, BOARD_HEIGHT - 3, BOARD_WIDTH - 4));
    blocks.push_back(new Square(SnakeRightPiece::color, BOARD_HEIGHT - 3, BOARD_WIDTH - 5));
    blocks.push_back(new Square(SnakeRightPiece::color, BOARD_HEIGHT - 4, BOARD_WIDTH - 5));
    blocks.push_back(new Square(SnakeRightPiece::color, BOARD_HEIGHT - 4, BOARD_WIDTH - 6));
}

SnakeRightPiece::~SnakeRightPiece() {}

void SnakeRightPiece::rotate()
{
}