//the tetris block super class
#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include "square.h"
#include <curses.h>

class Block
{
protected:
    std::vector<Square*> blocks;

public:
    Block();
    ~Block();
    void moveLeft();
    void moveRight();
    void moveDown();
    const std::vector<Square*> getSquares();
    virtual void rotate(){}; //override
};

#endif