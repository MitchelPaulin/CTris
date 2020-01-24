#include <curses.h>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <list>
#include "windows/border_window.h"
#include "windows/game_window.h"
#include "windows/window.h"
#include "string.h"
#include "constants.h"

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
	gameWin.test();
	gameWin.render();

	//game loop
	int s = 0;
	for (;;)
	{
		bannerWin.updateScore(s++);
		usleep(5000);
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
	for (int i = COLOR_RED; i <= COLOR_WHITE; i++)
	{
		init_pair(i, i, i);
	}
}