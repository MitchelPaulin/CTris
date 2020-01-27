//the tetris block super class
#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <curses.h>
#include "square.h"
#include "math.h"
class Block
{

public:
    Block();
    Block(std::vector<Square *>, Square*);
    ~Block();
    void moveLeft();
    void moveRight();
    void moveDown();
    void moveUp(); 
    virtual Block *rotate();
    const std::vector<Square *> getSquares();

protected:
    Square *centerOfRotation;
    std::vector<Square *> blocks;
};

#endif