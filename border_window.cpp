#include "border_window.h"
#include "ncurses.h"
#include "string.h"
#include "constants.h"

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

    char const *bannerString[5] = {
        "  ___  _____      _     ",
        " / __||_   _|_ _ (_) ___",
        "| (__   | | | '_|| |(_-<",
        " \\___|  |_| |_|  |_|/__/",
        "By: Mitchel Paulin"};

    for (int i = 0; i < 5; i++)
    {
        int padding = (WIDTH - strlen(bannerString[i]) - 1) / 2;
        wmove(this->getWin(), i + 1, padding);
        waddstr(this->getWin(), bannerString[i]);
    }

    wborder(this->getWin(), 0, 0, 0, 0, 0, 0, 0, 0);
}