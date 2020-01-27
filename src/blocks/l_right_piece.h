//The red right L piece
#ifndef L_RIGHT_PIECE_H
#define L_RIGHT_PIECE_H

#include "block.h"

class Block;

class LRightPiece : public Block
{
public:
    static const BLOCK_COLOR color = COLOR_RED;
    LRightPiece();
};

#endif