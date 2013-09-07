#ifndef INTROSTATE_H
#define	INTROSTATE_H

#include "../GameState.h"
#include "../../core/GameObject.h"

class IntroState : public GameState{
private:
    static IntroState instance;
    
private:
    IntroState();
    
public:
    void onActivate();
    void onDeactivate();
    void onLoop();
    void onRender();
    
    void onKeyDown(SDL_Keycode key, Uint16 mod);
    
    static IntroState * getInstance();
    
    GameObject * object;
    
private:

};

#endif	/* INTROSTATE_H */

