//The yellow square piece block
#ifndef SQUARE_PIECE_H
#define SQUARE_PIECE_H

#include "block.h"

class Block;

class SquarePiece : public Block
{
public:
    static const BLOCK_COLOR color = COLOR_YELLOW;
    SquarePiece();
    SquarePiece(SquarePiece* piece); 
    Block *rotate() override { return new SquarePiece(this); } //Square piece does not rotate 
};

#endif