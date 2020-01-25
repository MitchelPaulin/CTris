#include <vector>
#include "border_window.h"
#include "ncurses.h"
#include "string.h"
#include "../../include/constants.h"

const int scoreX = 31;
const int scoreY = 7;
const int length = 20;
const int nextX = 31;
const int nextY = 20;
std::vector<std::pair<int, int>> curPieceCords;
const char *bannerString[length] = {
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
    "Next:     "};

BorderWindow::BorderWindow(int width, int height, int startY, int startX) : Window(width, height, startY, startX)
{
    initWindow();
}

/*
    Change the score displayed on the banner, when this is called refresh will also be called 
*/
void BorderWindow::updateScore(int s)
{
    //use sprintf because we need a char*
    char scoreStr[9];
    sprintf(scoreStr, "%d", s);

    wmove(getWin(), scoreY, scoreX);
    waddstr(getWin(), scoreStr);

    refresh();
}

/*
    Draw the initial state of the window
*/
void BorderWindow::initWindow()
{

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

/*
    Draws the given block in the "next" spot on the UI
    Will redraw UI
*/
void BorderWindow::addNextBlock(Block block)
{
    //first, remove the currently drawn block 
    removeCurrentBlock();

    //find the leftmost block and use it as a drawing anchor
    Square *anchor = block.getSquares()[0];
    for (Square *s : block.getSquares())
    {
        if (anchor->getCol() > s->getCol())
        {
            anchor = s;
        }
    }

    //draw the shape using the anchor as a reference point
    for (Square *s : block.getSquares())
    {
        //save the locatoin of the currently draw piece so we can erase it without having to rerender the whole UI
        int x = (s->getCol() - anchor->getCol()) * 2 + nextX;
        int y = nextY - (s->getRow() - anchor->getRow());
        curPieceCords.push_back(std::pair<int, int>(y, x));
        //multiply by 2 because each box takes up two spaces
        wmove(getWin(), y, x);
        wattron(getWin(), COLOR_PAIR(s->getColor()));
        wprintw(getWin(), "  ");
        wattroff(getWin(), COLOR_PAIR(s->getColor()));
    }

    refresh();
}

/*
    Remove the current drawn block from the UI
    Should be called before you draw another next block 
*/
void BorderWindow::removeCurrentBlock()
{
    wattron(getWin(), COLOR_BLACK);
    while (!curPieceCords.empty())
    {
        auto cords = curPieceCords.back();
        curPieceCords.pop_back();
        wmove(getWin(), cords.first, cords.second);
        wprintw(getWin(), "  ");
        
    }
    wattroff(getWin(), COLOR_BLACK);
}