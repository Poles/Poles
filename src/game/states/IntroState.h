#ifndef INTROSTATE_H
#define	INTROSTATE_H

#include "../GameState.h"
#include "../../core/GameObject.h"
#include "../../core/Color.h"

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
    
private:
    GameObject * backgroundMountainAbove;
    GameObject * backgroundMountainBehind;
    GameObject * backgroundMountainSky;
    
    GameObject * title;
    
    GameObject * polesDude;
    
    Color titleColor;
    
    Uint32 initTime;
    Uint32 showTitleKeyTime;
    int durationTime;

};

#endif	/* INTROSTATE_H */

