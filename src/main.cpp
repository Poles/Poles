#include <iostream>
#include "game/Game.h"

#include "core/ResourceManager.h"

int main(int argc, char** argv) {
    ResourceManager::initialize();
    
    Game* game = new Game();
    game->start();
    
    delete game;
	
    return 0;
}
