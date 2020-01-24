#include <curses.h>
#include <iostream>
#include <vector>
#include <unistd.h> 
#include "windows/border_window.h"
#include "windows/game_window.h"
#include "windows/window.h"
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
	int s = 0;
	for (;;)
	{
		bannerWin.updateScore(s++); 
		usleep(5000); 

	}
	endwin();
	return 0;
}