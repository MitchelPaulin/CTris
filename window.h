//wrapper class for the main windows of the application
#ifndef WINDOW_H
#define WINDOW_H

#include <curses.h>

class Window
{
private:
    int width, height;

public:
    WINDOW *win;
    Window(int width, int height, int startX, int startY);
    int getWidth() { return width; };
    int getHeight() { return height; };
};

#endif