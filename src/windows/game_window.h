//the game window wrapper
#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include "window.h"
#include "../../include/constants.h"

class GameWindow : public Window
{

public:
    const static int ROWS = 26; //have some unrendered rows to hold pieces not yet on board
    const static int COLS = 10;
    GameWindow(int width, int height, int startY, int startX);
    void render();
    void initWindow();
    void test();
    bool isCellEmpty(int r, int c) const { return board[r][c] == EMPTY_CELL; };

private:
    BLOCK_COLOR board[ROWS][COLS];
};

#endif
