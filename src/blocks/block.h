//the tetris block super class
#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include "square.h"
#include <curses.h>
class Block
{

public:
    enum Direction
    {
        DOWN,
        LEFT,
        UP,
        RIGHT
    };
    
    Block();
    ~Block();
    void moveLeft();
    void moveRight();
    void moveDown();
    Direction getDir() { return dir; };
    const std::vector<Square *> getSquares();
    virtual void rotate(){}; //override

protected:
    std::vector<Square *> blocks;
    Direction dir = DOWN;
};

#endif