#include <curses.h>
#include <iostream>
#include <vector>
#include "window.h"
#include "string.h"

#define WIDTH 80
#define HEIGHT 30
#define BANNER_HEIGHT 7

void makeBanner(Window bannerWin);

int main(void)
{
	initscr();
	cbreak();	  //disable buffering
	start_color(); //enable colors
	noecho();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE); //catch special keys

	Window bannerWin = Window(BANNER_HEIGHT, WIDTH, 0, 0);
	makeBanner(bannerWin);
	wrefresh(stdscr);
	wrefresh(bannerWin.win);

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

/*
	Make the game banner 
*/
void makeBanner(Window bannerWin)
{

	char const *bannerString[5] = {
		"  ___  _____      _     ",
		" / __||_   _|_ _ (_) ___",
		"| (__   | | | '_|| |(_-<",
		" \\___|  |_| |_|  |_|/__/",
		"By: Mitchel Paulin"};

	for (int i = 0; i < 5; i++)
	{
		int padding = (WIDTH - strlen(bannerString[i]) - 1) / 2;
		wmove(bannerWin.win, i + 1, padding);
		waddstr(bannerWin.win, bannerString[i]);
	}

	wborder(bannerWin.win, 0, 0, 0, 0, 0, 0, 0, 0);
}