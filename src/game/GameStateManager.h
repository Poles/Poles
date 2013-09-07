#ifndef __Poles__GameStateManager__
#define __Poles__GameStateManager__

#include <iostream>
#include "GameState.h"

enum{
    GAMESTATE_NONE,
    GAMESTATE_INTRO,
    GAMESTATE_GAME,
    GAMESTATE_CONSOLE,
    GAMESTATE_DEBUG
};

class GameStateManager {
private:
    static GameState * currentState;
    
public:
    static void onEvent(SDL_Event * event);
    
    static void onLoop();
    
    static void onRender();
    
public:
    static void setGameState(int gameStateID);
    
    static GameState * getCurrentGameState();
};

#endif /* defined(__Poles__GameStateManager__) */
