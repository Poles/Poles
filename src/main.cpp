#include <iostream>
#include "engine/Game.h"


int main(int argc, char** argv)
{
    Game* game;

    game = new Game("Poles");
    game->createWindow();

    game->start();

    delete game;

    return 0;
}
