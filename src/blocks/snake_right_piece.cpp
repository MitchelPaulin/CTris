#include "snake_right_piece.h"

SnakeRightPiece::SnakeRightPiece()
{
    centerOfRotation = new Square(SnakeRightPiece::color, BOARD_HEIGHT - 3, BOARD_WIDTH - 5);

    blocks.push_back(centerOfRotation);
    blocks.push_back(new Square(SnakeRightPiece::color, BOARD_HEIGHT - 3, BOARD_WIDTH - 4));
    blocks.push_back(new Square(SnakeRightPiece::color, BOARD_HEIGHT - 4, BOARD_WIDTH - 5));
    blocks.push_back(new Square(SnakeRightPiece::color, BOARD_HEIGHT - 4, BOARD_WIDTH - 6));
}