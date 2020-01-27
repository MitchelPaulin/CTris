#include "l_right_piece.h"

LRightPiece::LRightPiece()
{
    centerOfRotation = new Square(LRightPiece::color, BOARD_HEIGHT - 4, BOARD_WIDTH - 5);

    blocks.push_back(centerOfRotation);
    blocks.push_back(new Square(LRightPiece::color, BOARD_HEIGHT - 3, BOARD_WIDTH - 4));
    blocks.push_back(new Square(LRightPiece::color, BOARD_HEIGHT - 4, BOARD_WIDTH - 4));
    blocks.push_back(new Square(LRightPiece::color, BOARD_HEIGHT - 4, BOARD_WIDTH - 6));
}