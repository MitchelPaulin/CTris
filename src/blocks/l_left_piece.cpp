#include "l_left_piece.h"

LLeftPiece::LLeftPiece()
{
    centerOfRotation = new Square(LLeftPiece::color, BOARD_HEIGHT - 4, BOARD_WIDTH - 5);

    blocks.push_back(centerOfRotation);
    blocks.push_back(new Square(LLeftPiece::color, BOARD_HEIGHT - 3, BOARD_WIDTH - 6));
    blocks.push_back(new Square(LLeftPiece::color, BOARD_HEIGHT - 4, BOARD_WIDTH - 4));
    blocks.push_back(new Square(LLeftPiece::color, BOARD_HEIGHT - 4, BOARD_WIDTH - 6));
}