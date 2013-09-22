#include "GameStateManager.h"
#include "states/DebugState.h"
#include "states/IntroState.h"
#include "states/ParallaxTest.h"

GameState * GameStateManager::currentState = NULL;

/**
 * 
 * @param event
 */
void GameStateManager::onEvent(SDL_Event * event) {
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
            currentState = IntroState::getInstance();
            break;
            
        case GAMESTATE_GAME:
            
            break;
            
        case GAMESTATE_CONSOLE:
            
            break;
            
        case GAMESTATE_DEBUG:
            currentState = DebugState::getInstance();
            break;
            
        case GAMESTATE_PARALLAX_TEST:
            currentState = ParallaxTest::getInstance();
            break;
        }
    
    if (currentState != NULL) {
            currentState->onActivate();
    }
}

/**
 * 
 * @return 
 */
GameState * GameStateManager::getCurrentGameState() {
    return currentState;
}

void GameStateManager::freeAllResources() {
    currentState->onDeactivate();
}
