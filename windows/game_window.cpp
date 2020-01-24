#include "game_window.h"
#include "../constants.h"
#include "curses.h"

GameWindow::GameWindow(int width, int height, int startY, int startX) : Window(width, height, startY, startX)
{
    GameWindow::initWindow(); 
}

/*
    Override
    Draw the initial state of the window
*/ 
void GameWindow::initWindow()
{
    wborder(getWin(), 0, 0, 0, 0, 0, 0, 0, 0);

    //draw title 
    wmove(getWin(), 0, (GAME_WIDTH / 2) - 2);
    waddstr(getWin(), "CTris");
}