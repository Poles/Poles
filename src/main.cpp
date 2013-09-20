#include <iostream>
#include "game/Game.h"

#include "core/ResourceManager.h"
#include "game/GameStateManager.h"

int main(int argc, char** argv) {
    ResourceManager::initialize();
    
    Game* game = new Game();
    game->start();
    
    delete game;

    ResourceManager::freeAllResources();
    GameStateManager::freeAllResources();

    return 0;
}
