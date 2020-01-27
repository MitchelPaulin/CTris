//The cyan long piece block
#ifndef BLUE_PIECE_H
#define BLUE_PIECE_H

#include "block.h"

class Block;

class LongPiece : public Block
{
public:
    static const BLOCK_COLOR color = COLOR_CYAN;
    LongPiece();
    LongPiece(std::vector<Square*>, Square* center);
    Block *rotate() override;

private:
    enum Direction
    {
        UP,
        LEFT,
        DOWN,
        RIGHT
    };
    Direction dir = Direction::RIGHT; 
};

#endif