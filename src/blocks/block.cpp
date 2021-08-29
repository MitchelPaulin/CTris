#include "block.h"

Block::Block() {}

Block::Block(std::vector<Square *> squares, Square *center)
{
    blocks = squares;
    centerOfRotation = center;
}

Block::~Block()
{
    while (!Block::blocks.empty())
    {
        blocks.pop_back();
    }
}

void Block::moveDown()
{
    for (Square *s : blocks)
    {
        s->bumpDown();
    }
}

void Block::moveRight()
{
    for (Square *s : blocks)
    {
        s->bumpRight();
    }
}

void Block::moveLeft()
{
    for (Square *s : blocks)
    {
        s->bumpLeft();
    }
}

void Block::moveUp()
{
    for (Square *s : blocks)
    {
        s->bumpUp();
    }
}

const std::vector<Square *> Block::getSquares()
{
    return blocks;
}

/*
    Rotate a block around its center
*/
Block *Block::rotate()
{
    std::vector<Square *> newSquares;
    Square *center = nullptr;
    for (Square *s : blocks)
    {
        if (s == centerOfRotation)
        {
            center = new Square(s->getColor(), centerOfRotation->getRow(), centerOfRotation->getCol());
            newSquares.push_back(center);
            continue;
        }

        newSquares.push_back(Square::rotateSquareAboutCenter(centerOfRotation, s));
    }

    Block *ret = new Block(newSquares, center);
    return ret;
}