//the tetris block super class
#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include "square.h"
#include <curses.h>

class Block
{
protected:
    Block(); //dont allows class to be instantiated 
    ~Block();
    std::vector<Square> blocks;

public:
    void moveLeft();
    void moveRight();
    void moveDown();
    virtual void rotate(){}; //override
};

#endif