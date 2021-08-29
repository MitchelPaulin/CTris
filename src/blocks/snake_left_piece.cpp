#include "snake_left_piece.h"

SnakeLeftPiece::SnakeLeftPiece()
{
    centerOfRotation = new Square(SnakeLeftPiece::color, BOARD_HEIGHT - 3, BOARD_WIDTH - 5);

    blocks.push_back(centerOfRotation);
    blocks.push_back(new Square(SnakeLeftPiece::color, BOARD_HEIGHT - 3, BOARD_WIDTH - 6));
    blocks.push_back(new Square(SnakeLeftPiece::color, BOARD_HEIGHT - 4, BOARD_WIDTH - 5));
    blocks.push_back(new Square(SnakeLeftPiece::color, BOARD_HEIGHT - 4, BOARD_WIDTH - 4));
}
