#include "window.h"

Window::Window(int width, int height, int startX, int startY)
{
    this->width = width;
    this->height = height;
    this->startX = startX;
    this->startY = startY;

    this->win = newwin(width, height, startY, startX);
}