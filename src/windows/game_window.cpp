#include "game_window.h"
#include "curses.h"

GameWindow::GameWindow(int width, int height, int startY, int startX) : Window(width, height, startY, startX)
{
    GameWindow::initWindow();
}

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
    for (int i = ROWS - 5; i >= 0; i--)
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

void GameWindow::eraseBlock(Block block)
{
    for (Square *s : block.getSquares())
    {
        board[s->getRow()][s->getCol()] = EMPTY_CELL;
    }
}

void GameWindow::drawBlock(Block block)
{
    for (Square *s : block.getSquares())
    {
        board[s->getRow()][s->getCol()] = s->getColor();
    }
}

bool GameWindow::blockCollides(Block block)
{
    for (Square *s : block.getSquares())
    {
        if (s->getRow() < 0 || s->getRow() >= ROWS || s->getCol() < 0 || s->getCol() >= COLS || !isCellEmpty(s->getRow(), s->getCol()))
        {
            return true;
        }
    }
    return false;
}

/*
    Remove any completed lines from the game 
    Returns the number of lines removed for scoring purposes 
*/
int GameWindow::removeCompletedLines()
{
    int linesRemoved = 0;
    for (int r = 0; r < ROWS; r++)
    {
        bool lineFull = true;
        for (int c = 0; c < COLS; c++)
        {
            if (board[r][c] == EMPTY_CELL)
            {
                lineFull = false;
                break;
            }
        }
        //Erase line
        if (lineFull)
        {
            linesRemoved++;

            for (int c = 0; c < COLS; c++)
            {
                board[r][c] = EMPTY_CELL;
            }
            //Everything above this lines must be shifted one down
            for (int i = r; i < ROWS - 1; i++)
            {
                for (int j = 0; j < COLS; j++)
                {
                    board[i][j] = board[i + 1][j];
                }
            }

            //Since we removed a row we must check the row we visited again
            r--;
        }
    }

    return linesRemoved;
}

void GameWindow::fillScreen()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            board[i][j] = ((i + j) % COLOR_WHITE) + 1;
        }
    }
}