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

	//Construct windows
	BorderWindow bannerWin = BorderWindow(HEIGHT, WIDTH, GAME_WIDTH, 0);
	GameWindow gameWin = GameWindow(HEIGHT, GAME_WIDTH, 0, 0);
	gameWin.render();

	//Prvent wgetch from being a blocking call
	nodelay(bannerWin.getWin(), TRUE);

	//Create a Tpiece just to make sure we can
	Block curPiece = TPiece();

	int score = 0;
	int downTimer = 0; //once this hits a certain number of loops we move the block down
	char userInput;

	//game loop
	for (;;)
	{
		//bannerWin.updateScore(s++);
		gameWin.eraseBlock(curPiece);

		if (downTimer > BLOCK_FALL_SPEED)
		{
			curPiece.moveDown();
			downTimer = 0;
		}
		else
		{
			downTimer++;
		}

		//process user input
		userInput = wgetch(bannerWin.getWin());
		if (userInput == 'd' || userInput == 'D')
		{
			curPiece.moveRight();
		}
		else if (userInput == 'a' || userInput == 'A')
		{
			curPiece.moveLeft();
		}
		else if (userInput == 'w' || userInput == 'W')
		{
			/* code */
		}
		else if (userInput == 's' || userInput == 'S')
		{
			/* code */
		}
		else if (userInput == 'r' || userInput == 'R')
		{
			/* code */
		}
		else if (userInput == 'e' || userInput == 'E')
		{
			break;
		}

		//rerender screen with new block location
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