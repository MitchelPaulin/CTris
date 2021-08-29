#include <vector>
#include "border_window.h"
#include "ncurses.h"
#include "string.h"
#include "../../include/constants.h"

const int scoreX = 31;
const int scoreY = 7;
const int length = 19;
const int nextX = 31;
const int nextY = 19;
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
    "__Controls__",
    "Left:       A | ←",
    "Right:      D | →",
    "Down:       S | ↓",
    "Rotate:     W | ↑",
    "Drop:     Space ",
    "Restart:      R ",
    "Exit:       Esc ",
    "",
    "",
    "Next:     "};

BorderWindow::BorderWindow(int width, int height, int startY, int startX) : Window(width, height, startY, startX)
{
    initWindow();
}

/*
    Change the score displayed on the banner
*/
void BorderWindow::updateScore(int s)
{
    //Use sprintf because waddstr needs a char*
    char scoreStr[9];
    sprintf(scoreStr, "%d", s);

    wmove(getWin(), scoreY, scoreX);
    waddstr(getWin(), scoreStr);

    refresh();
}

void BorderWindow::initWindow()
{
    wclear(getWin());
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
*/
void BorderWindow::addNextBlock(Block block)
{
    removeCurrentBlock();

    //Find the leftmost and topmost block and use it as a drawing anchor
    Square *xAnchor = block.getSquares()[0];
    Square *yAnchor = block.getSquares()[0];
    for (Square *s : block.getSquares())
    {
        if (xAnchor->getCol() > s->getCol())
        {
            xAnchor = s;
        }

        if (yAnchor->getRow() < s->getRow())
        {
            yAnchor = s;
        }
    }

    //Draw the shape using the anchor as a reference point
    for (Square *s : block.getSquares())
    {
        //Save the location of the currently drawn piece so we can erase it without having to re render the whole UI
        int x = (s->getCol() - xAnchor->getCol()) * 2 + nextX; //multiply by 2 because each box takes up two spaces
        int y = nextY - (s->getRow() - yAnchor->getRow());
        curPieceCords.push_back(std::pair<int, int>(y, x));

        //Draw block
        wmove(getWin(), y, x);
        wattron(getWin(), COLOR_PAIR(s->getColor()));
        wprintw(getWin(), "  ");
        wattroff(getWin(), COLOR_PAIR(s->getColor()));
    }

    refresh();
}

/*
    Remove the currently drawn block from the UI
    Should be called before you draw another "next" block 
*/
void BorderWindow::removeCurrentBlock()
{
    wattron(getWin(), EMPTY_CELL);
    while (!curPieceCords.empty())
    {
        auto cords = curPieceCords.back();
        curPieceCords.pop_back();
        wmove(getWin(), cords.first, cords.second);
        wprintw(getWin(), "  ");
    }
    wattroff(getWin(), EMPTY_CELL);
}