//The white left L piece
#ifndef L_LEFT_PIECE_H
#define L_LEFT_PIECE_H

#include "block.h"

class Block;

class LLeftPiece : public Block
{
public:
    static const BLOCK_COLOR color = COLOR_WHITE;
    LLeftPiece();
};

#endif