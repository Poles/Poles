#ifndef DEBUGSTATE_H
#define	DEBUGSTATE_H

#include "../GameState.h"
#include "../../core/GameObject.h"

class DebugState : public GameState{
public:    
    static DebugState * getInstance();
    
    void onActivate();
    
    void onDeactivate();
    
    void onLoop();
    
    void onRender();
    
    void onKeyDown(SDL_Keycode key, Uint16 mod);
    
    void onKeyUp(SDL_Keycode key, Uint16 mod);
    
private:
    DebugState();
    
    ~DebugState();
        
private:
    static DebugState instance;
    
    GameObject * polesDude;

};

#endif	/* DEBUGSTATE_H */

