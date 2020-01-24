#include "border_window.h"
#include "ncurses.h"
#include "string.h"
#include "../constants.h"

BorderWindow::BorderWindow(int width, int height, int startY, int startX) : Window(width, height, startY, startX)
{
    initWindow(); 
}

void BorderWindow::updateScore(int scores)
{
    //TODO implement
}

void BorderWindow::initWindow()
{
    int length = 20; 
    char const *bannerString[length] = {
        "  ___  _____      _     ",
        " / __||_   _|_ _ (_) ___",
        "| (__   | | | '_|| |(_-<",
        " \\___|  |_| |_|  |_|/__/",
        "By: Mitchel Paulin",
        "",
        "",
        "Score: 0",
        "",
        "",
        "Controls",
        "",
        "Left:        a",
        "Right:       d",
        "Down:        s",
        "Rotate:      w",
        "Drop:    space",
        "",
        "",
        "Next:"};

    for (int i = 0; i < length; i++)
    {
        int padding = (WIDTH - strlen(bannerString[i]) - 1) / 2;
        wmove(this->getWin(), i + 1, padding);
        waddstr(this->getWin(), bannerString[i]);
    }

    wborder(this->getWin(), 0, 0, 0, 0, 0, 0, 0, 0);
}