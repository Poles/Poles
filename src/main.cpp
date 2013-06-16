#include <iostream>
#include "Game.h"

int main(int argc, char** argv)
{
    Game* game = new Game();
    game->start();
    
    delete game;
	
    return 0;
}
