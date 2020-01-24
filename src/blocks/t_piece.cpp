#include "t_piece.h"

TPiece::TPiece()
{
    //Create 4 squares for the TPiece
    blocks = {
        Square(TPiece::color, BOARD_HEIGHT - 3, BOARD_WIDTH - 3),
        Square(TPiece::color, BOARD_HEIGHT - 3, BOARD_WIDTH - 2),
        Square(TPiece::color, BOARD_HEIGHT - 3, BOARD_WIDTH - 1),
        Square(TPiece::color, BOARD_HEIGHT - 4, BOARD_WIDTH - 2)};
}

void TPiece::rotate()
{
}