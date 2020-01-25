#include <curses.h>
#include <vector>
#include <unistd.h>
#include <list>
#include <random>
#include "windows/border_window.h"
#include "windows/game_window.h"
#include "../include/constants.h"
#include "../include/all_blocks.h"

void reInit(const std::list<Window> &Windows);
void initColors();
bool canMoveRight(Block block, GameWindow &win);
bool canMoveLeft(Block block, GameWindow &win);
bool canMoveDown(Block block, GameWindow &win);
Block createNewBlock(int num);

int main(void)
{
	initscr();
	cbreak();	  //disable buffering
	start_color(); //enable colors
	initColors();
	noecho();

	//Initialize random number generator
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(1, BLOCK_TYPES);

	//Construct windows
	BorderWindow bannerWin = BorderWindow(HEIGHT, WIDTH, GAME_WIDTH, 0);
	GameWindow gameWin = GameWindow(HEIGHT, GAME_WIDTH, 0, 0);
	gameWin.render();

	//Prevent wgetch from being a blocking call
	nodelay(bannerWin.getWin(), TRUE);

	//Create the two initial pieces
	Block curPiece = createNewBlock(dist6(rng));
	Block nextPiece = createNewBlock(dist6(rng));
	bannerWin.addNextBlock(nextPiece);

	int score = 0;
	int downTimer = 0; //once this hits a certain number of loops we move the block down
	char userInput;

	//Game loop
	for (;;)
	{
		//Erase block so we can redraw it in new location
		gameWin.eraseBlock(curPiece);

		//Process user input
		userInput = wgetch(bannerWin.getWin());
		if (userInput == 'd' || userInput == 'D')
		{
			if (canMoveRight(curPiece, gameWin))
			{
				curPiece.moveRight();
			}
		}
		else if (userInput == 'a' || userInput == 'A')
		{
			if (canMoveLeft(curPiece, gameWin))
			{
				curPiece.moveLeft();
			}
		}
		else if (userInput == 'w' || userInput == 'W')
		{
			curPiece.rotate(); //Implement this function
		}
		else if (userInput == 's' || userInput == 'S')
		{
			if (canMoveDown(curPiece, gameWin))
			{
				curPiece.moveDown();
				downTimer = 0; //Reset down timer
			}
		}
		else if (userInput == 'r' || userInput == 'R')
		{
			/* code */
		}
		else if (userInput == 'e' || userInput == 'E')
		{
			break; //Exit
		}
		else if (userInput == ' ') //spacebar pressed
		{
			while (canMoveDown(curPiece, gameWin))
			{
				curPiece.moveDown();
			}
			downTimer = BLOCK_FALL_SPEED; //block reached bottom, force spawn
		}

		//Move block down
		if (downTimer > BLOCK_FALL_SPEED)
		{
			if (canMoveDown(curPiece, gameWin))
			{
				curPiece.moveDown();
				downTimer = 0;
			}
			else
			{
				//Piece reached bottom, check if player looses
				//If any block is still "in play" then continue 
				bool lost = true;
				for (Square *s : curPiece.getSquares())
				{
					if (s->getRow() < BOARD_TOP - 2)
					{
						lost = false;
					}
				}

				if (lost)
				{
					break; //just exit program on loss for now 
				}

				//Spawn next piece and setup UI
				gameWin.drawBlock(curPiece);
				curPiece = nextPiece;
				nextPiece = createNewBlock(dist6(rng));
				bannerWin.addNextBlock(nextPiece);
				continue;
			}
		}
		else
		{
			downTimer++;
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
	Returns a new tetris block 
*/
Block createNewBlock(int num)
{
	switch (num)
	{
	case 1:
		return LLeftPiece();
	case 2:
		return LRightPiece();
	case 3:
		return LongPiece();
	case 4:
		return SnakeLeftPiece();
	case 5:
		return SnakeRightPiece();
	case 6:
		return SquarePiece();
	case 7:
		return TPiece();
	default:
		return TPiece();
	}
}

/*
	Determin if given the current block whether or not we can move right 
*/
bool canMoveRight(Block block, GameWindow &win)
{
	for (Square *s : block.getSquares())
	{
		if (s->getCol() == BOARD_WIDTH - 1 || !win.isCellEmpty(s->getRow(), s->getCol() + 1))
		{
			return false;
		}
	}
	return true;
}

/*
	Determine if given the current block whether or not we can move left
*/
bool canMoveLeft(Block block, GameWindow &win)
{
	for (Square *s : block.getSquares())
	{
		if (s->getCol() <= 0 || !win.isCellEmpty(s->getRow(), s->getCol() - 1))
		{
			return false;
		}
	}
	return true;
}

/*
	Determine if given the current block whether or not we can move down
*/
bool canMoveDown(Block block, GameWindow &win)
{
	for (Square *s : block.getSquares())
	{
		if (s->getRow() <= 0 || !win.isCellEmpty(s->getRow() - 1, s->getCol()))
		{
			return false;
		}
	}
	return true;
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