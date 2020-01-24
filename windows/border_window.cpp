#include "border_window.h"
#include "ncurses.h"
#include "string.h"
#include "../constants.h"

BorderWindow::BorderWindow(int width, int height, int startY, int startX) : Window(width, height, startY, startX)
{
    initWindow();
}

/*
    Change the score displayed on the banner, when this is called refresh will also be called 
*/
void BorderWindow::updateScore(int score)
{
    int scoreX = 31; 
    int scoreY = 7;

    //use sprintf because we need a char*
    char scoreStr[9];
    sprintf(scoreStr, "%d", score);

    wmove(getWin(), scoreY, scoreX);
    waddstr(getWin(), scoreStr);

    refresh();
}

/*
    Draw the initial state of the window
*/
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
        "Score: 0",
        "",
        "Controls",
        "",
        "Left:        A",
        "Right:       D",
        "Down:        S",
        "Rotate:      W",
        "Drop:    Space",
        "Restart:     R",
        "Exit:        E",
        "",
        "", 
        "Next:            "};

    //Draw every line and also center it within the frame 
    for (int i = 0; i < length; i++)
    {
        int padding = (WIDTH - strlen(bannerString[i]) - 1) / 2;
        wmove(getWin(), i + 1, padding);
        waddstr(getWin(), bannerString[i]);
    }

    wborder(getWin(), 0, 0, 0, 0, 0, 0, 0, 0);

    refresh(); 
}