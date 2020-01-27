//the game window wrapper
#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include "window.h"
#include "../../include/constants.h"
#include "../../include/all_blocks.h"

class Block; 

class GameWindow : public Window
{

public:
    const static int ROWS = BOARD_HEIGHT; //have some unrendered rows to hold pieces not yet on board
    const static int COLS = BOARD_WIDTH;
    GameWindow(int width, int height, int startY, int startX);
    void render();
    void initWindow();
    void fillScreen();
    void eraseBlock(Block); 
    void drawBlock(Block);
    bool blockCollides(Block); 
    int removeCompletedLines(); 
    bool isCellEmpty(int r, int c) const { return board[r][c] == EMPTY_CELL; };

private:
    BLOCK_COLOR board[ROWS][COLS];
};

#endif
