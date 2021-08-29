#ifndef BORDER_WINDOW_H
#define BORDER_WINDOW_H

#include "window.h"
#include "../blocks/block.h"

class BorderWindow : public Window
{
public:
    void updateScore(int score);
    void initWindow();
    void addNextBlock(Block);
    BorderWindow(int width, int height, int startY, int startX);

private:
    void removeCurrentBlock();
};

#endif