#include "GameStateManager.h"

GameState * GameStateManager::currentState = NULL;

/**
 * 
 * @param event
 */
void GameStateManager::onEvent(SDL_Event* event) {
    if (currentState != NULL) {
        currentState->onEvent(event);
    }
}

/**
 * 
 */
void GameStateManager::onLoop() {
    if (currentState != NULL) {
        currentState->onLoop();
    }
}

/**
 * 
 */
void GameStateManager::onRender() {
    if (currentState != NULL) {
        currentState->onRender();
    }
}

/**
 * 
 * @param gameStateID
 */
void GameStateManager::setGameState(int gameStateID) {
    if (currentState != NULL) {
        currentState->onDeactivate();
    }    
    
    switch (gameStateID) {
        case GAMESTATE_NONE:
            currentState = NULL;
            break;
            
        case GAMESTATE_INTRO:
            
            break;
            
        case GAMESTATE_GAME:
            
            break;
            
        case GAMESTATE_CONSOLE:
            
            break;
            
        default:
            currentState = NULL;
            break;
            
        if (currentState != NULL) {
            currentState->onActivate();
        }
    }
}

/**
 * 
 * @return 
 */
GameState * GameStateManager::getCurrentGameState() {
    return currentState;
}
