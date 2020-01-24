//wrapper class for the main windows of the application
//should be extended for particular functionality
#ifndef WINDOW_H
#define WINDOW_H

#include "curses.h"

class Window
{
private:
    int width, height, startX, startY;
    WINDOW *win;

public:
    Window(int width, int height, int startY, int startX);
    int getWidth() { return width; };
    int getHeight() { return height; };
    int getStartX() { return startX; };
    int getStartY() { return startY; };
    WINDOW *getWin() { return win; };
    void refresh() { wrefresh(win); };
    virtual void initWindow() {}; //override
};

#endif