#include <curses.h>
#include <vector>
#include <unistd.h>
#include <list>
#include "windows/border_window.h"
#include "windows/game_window.h"
#include "../include/constants.h"
#include "../include/all_blocks.h"

void reInit(const std::list<Window> &Windows);
void initColors();

int main(void)
{
	initscr();
	cbreak();	  //disable buffering
	start_color(); //enable colors
	initColors();
	noecho();
	nodelay(stdscr, TRUE);

	//Construct windows
	BorderWindow bannerWin = BorderWindow(HEIGHT, WIDTH, GAME_WIDTH, 0);
	GameWindow gameWin = GameWindow(HEIGHT, GAME_WIDTH, 0, 0);
	gameWin.render();

	//Create a Tpiece just to make sure we can
	Block curPiece = TPiece();

	//game loop
	int s = 0;
	for (;;)
	{
		//bannerWin.updateScore(s++);
		gameWin.eraseBlock(curPiece);
		curPiece.moveDown();
		gameWin.drawBlock(curPiece);
		gameWin.render(); 
		usleep(CLOCK_SPEED);
	}
	endwin();
	return 0;
}

/*
	Call the overriden function of every window to reinitialize it 
*/
void reInit(const std::list<Window> &Windows)
{
	for (auto w : Windows)
	{
		w.initWindow();
	}
}

/*
	Create all colors pairs for use later 
*/
void initColors()
{
	for (int i = COLOR_BLACK; i <= COLOR_WHITE; i++)
	{
		init_pair(i, i, i);
	}
}