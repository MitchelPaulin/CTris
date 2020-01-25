#include "block.h"

Block::Block() {}
Block::~Block() {}

//return an non editable vector of this block

/*
    Attempt to move this piece down 
*/
void Block::moveDown()
{
    //move every piece one down 
    for (Square* s : blocks)
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
    for (Square* s : blocks)
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
    for (Square* s : blocks)
    {
        s->bumpLeft();
    }
}

const std::vector<Square*> Block::getSquares()
{
    return blocks;
}