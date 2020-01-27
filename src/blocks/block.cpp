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

/*
    Attempt to move this piece down 
*/
void Block::moveDown()
{
    //move every piece one down
    for (Square *s : blocks)
    {
        s->bumpDown();
    }
}

/*
    Attempt to move this piece right 
*/
void Block::moveRight()
{
    //move every piece one to the right
    for (Square *s : blocks)
    {
        s->bumpRight();
    }
}

/*
    Attempt to move this piece left 
*/
void Block::moveLeft()
{
    //move every piece one to the left
    for (Square *s : blocks)
    {
        s->bumpLeft();
    }
}

/*
    Attempt to move this piece up 
*/
void Block::moveUp()
{
    for (Square *s : blocks)
    {
        s->bumpUp();
    }
}

/*
    Return the squares that make up this piece 
*/
const std::vector<Square *> Block::getSquares()
{
    return blocks;
}

/*
    Rotate a block around a give center
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