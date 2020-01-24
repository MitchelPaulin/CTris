//the game window wrapper
#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include "window.h"

class GameWindow : public Window
{
private:
    

public:
    GameWindow(int width, int height, int startY, int startX); 
    void initWindow(); 
};

#endif
