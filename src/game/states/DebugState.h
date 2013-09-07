#ifndef DEBUGSTATE_H
#define	DEBUGSTATE_H

#include "../GameState.h"
#include "../../core/GameObject.h"

class DebugState : public GameState {
public:    
    DebugState();
    
    ~DebugState();    
    
    void onActivate();
    
    void onDeactivate();
    
    void onLoop();
    
    void onRender();
    
    void onKeyDown(SDL_Keycode key, Uint16 mod);
    
    void onKeyUp(SDL_Keycode key, Uint16 mod); 
        
private:    
    GameObject * polesDude;
    GameObject * text;
    bool keyDown;

};

#endif	/* DEBUGSTATE_H */

