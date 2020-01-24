#include <curses.h>
#include <iostream>
#include <vector>
#include "border_window.h"
#include "game_window.h"
#include "window.h"
#include "string.h"
#include "constants.h"

int main(void)
{
	initscr();
	cbreak();	  //disable buffering
	start_color(); //enable colors
	noecho();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE); //catch special keys

	//Construct windows 
	BorderWindow bannerWin = BorderWindow(HEIGHT, WIDTH, GAME_WIDTH, 0);
	GameWindow gameWin = GameWindow(HEIGHT, GAME_WIDTH, 0, 0); 

	wrefresh(stdscr);
	wrefresh(bannerWin.getWin());
	wrefresh(gameWin.getWin()); 

	//game loop
	int ch;
	for (;;)
	{
		if ((ch = getch()) == ERR)
		{
			//no input received
		}
		else
		{
			if (ch == KEY_UP)
			{
			}
		}
	}
	endwin();
	return 0;
}