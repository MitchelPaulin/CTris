#include "block.h"

Block::Block() {}
Block::~Block() {}

void Block::moveDown()
{
}

/*
    Attempt to move this piece right 
*/
void Block::moveRight()
{
    //can this move right?
    for (Square s : blocks)
    {
        if (s.getCol())
        {
            return;
        }
    }

    //move every piece one to the right
    for (Square s : blocks)
    {
        s.bumpRight();
    }
}

/*
    Attempt to move this piece left 
*/
void Block::moveLeft()
{
    //can this move left?
    for (Square s : blocks)
    {
        if (s.getCol() == 0)
        {
            return;
        }
    }

    //move every piece one to the left
    for (Square s : blocks)
    {
        s.bumpLeft();
    }
}