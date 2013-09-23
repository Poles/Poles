#include <iostream>

#include "game/PolesGame.h"


int main(int argc, char** argv)
{
    PolesGame* game;

    game = new PolesGame();
    game->createWindow();

    game->start();

    delete game;

    return 0;
}
