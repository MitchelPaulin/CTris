#include "game_window.h"
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

    //init to empty cells
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            board[i][j] = EMPTY_CELL;
        }
    }

    refresh();
}

/*
    Draw the current game state to the board
*/
void GameWindow::render()
{
    int curRow = 1;
    for (int i = 21; i >= 0; i--)
    {
        wmove(getWin(), curRow++, 1); //move cursor to next line
        for (int j = 0; j < COLS; j++)
        {
            BLOCK_COLOR cell = board[i][j];
            if (cell == EMPTY_CELL)
            {
                wattron(getWin(), COLOR_PAIR(COLOR_BLACK));
                wprintw(getWin(), ". ");
                wattroff(getWin(), COLOR_PAIR(COLOR_BLACK));
            }
            else
            {
                wattron(getWin(), COLOR_PAIR(cell));
                wprintw(getWin(), "  ");
                wattroff(getWin(), COLOR_PAIR(cell));
            }
        }
    }

    refresh();
}

/*
    Remove this block from the array
*/
void GameWindow::eraseBlock(Block block)
{
    for (Square* s : block.getSquares())
    {
        board[s->getRow()][s->getCol()] = EMPTY_CELL;
    }
}

/*
    Put the block in the array 
*/
void GameWindow::drawBlock(Block block)
{
    for (Square* s : block.getSquares())
    { 
        board[s->getRow()][s->getCol()] = s->getColor();
    }
}

/*
    Fill board with colors to test rendering  
*/
void GameWindow::test()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            board[i][j] = i % COLOR_WHITE;
        }
    }
}