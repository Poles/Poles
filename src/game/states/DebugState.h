#ifndef DEBUGSTATE_H
#define	DEBUGSTATE_H

#include "../GameState.h"
#include "../../core/GameObject.h"
#include "../../core/components/Components.h"

class DebugState : public GameState {
private:
    static DebugState instance;
    
private:
    DebugState();
    
public:
    static DebugState * getInstance();
    
    void onActivate();
    
    void onDeactivate();
    
    void onLoop();
    
    void onRender();
    
    void onKeyDown(SDL_Keycode key, Uint16 mod);
    
    void onKeyUp(SDL_Keycode key, Uint16 mod); 
        
private:
    GameObject * zero;
    GameObject * background;

    GameObject * debugInfo;
    GameObject * zeroInfo;
    components::TextRenderer * text;
    components::TextRenderer * zeroText;
    bool keyDown;

};

#endif	/* DEBUGSTATE_H */

