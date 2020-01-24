#include "game_window.h"
#include "constants.h"
#include "curses.h"

GameWindow::GameWindow(int width, int height, int startY, int startX) : Window(width, height, startY, startX)
{
    GameWindow::initWindow(); 
}

void GameWindow::initWindow()
{
    wborder(this->getWin(), 0, 0, 0, 0, 0, 0, 0, 0);
    wmove(this->getWin(), 0, (GAME_WIDTH / 2) - 3);
    waddstr(this->getWin(), "Ctris");
}