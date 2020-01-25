//The blue long piece block

#ifndef BLUE_PIECE_H
#define BLUE_PIECE_H

#include "block.h"

class Block;

class LongPiece : public Block
{
public:
    static const BLOCK_COLOR color = COLOR_CYAN;
    void rotate() override;
    LongPiece();
    ~LongPiece();
};

#endif