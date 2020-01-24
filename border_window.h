//the border window wrapper
#ifndef BORDER_WINDOW_H
#define BORDER_WINDOW_H

#include "window.h"

class BorderWindow : public Window
{
public:
    void updateScore(int score);
    void initWindow(); 
    BorderWindow(int width, int height, int startY, int startX); 
};

#endif