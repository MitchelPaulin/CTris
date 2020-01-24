#include <exception>
#include "window.h"

Window::Window(int width, int height, int startX, int startY)
{
    this->width = width;
    this->height = height;

    this->win = newwin(width, height, startX, startY);
}