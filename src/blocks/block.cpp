#include <algorithm>
#include "block.h"

void Block::moveDown(const GameWindow win)
{
}

/*
    Attempt to move this piece right 
*/
void Block::moveRight(const GameWindow win)
{
    //can this move right?
    for (Square s : blocks)
    {
        if (s.getCol() == GameWindow::COLS - 1 || !win.isCellEmpty(s.getRow(), s.getCol() + 1))
        {
            return;
        }
    }

    //move every piece one to the right
    std::for_each(blocks.begin(), blocks.end(), Square::bumpRight);
}

/*
    Attempt to move this piece left 
*/
void Block::moveLeft(const GameWindow win)
{
    //can this move left?
    for (Square s : blocks)
    {
        if (s.getCol() == 0 || !win.isCellEmpty(s.getRow(), s.getCol() - 1))
        {
            return;
        }
    }

    //move every piece one to the left
    std::for_each(blocks.begin(), blocks.end(), Square::bumpLeft);
}