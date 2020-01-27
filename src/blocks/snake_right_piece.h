//The blue right snake piece
#ifndef SNAKE_RIGHT_PIECE_H
#define SNAKE_RIGHT_PIECE_H

#include "block.h"

class Block;

class SnakeRightPiece : public Block
{
public:
    static const BLOCK_COLOR color = COLOR_BLUE;
    SnakeRightPiece();
};

#endif