//the tetris block super class
#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <square.h>
#include "game_window.h"

class Block
{
protected:
    std::vector<Square> blocks;

public:
    void moveLeft(const GameWindow);
    void moveRight(const GameWindow);
    void moveDown(const GameWindow);
    virtual void rotate();
};

#endif