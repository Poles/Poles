#ifndef PARALLAXTEST_H
#define	PARALLAXTEST_H

#include "../GameState.h"
#include "../../core/GameObject.h"

class ParallaxTest : public GameState {
private:
    static ParallaxTest instance;
    
private:
    ParallaxTest();
    
public:
    static ParallaxTest* getInstance();
    
    void onActivate();
    
    void onDeactivate();
    
    void onLoop();
    
    void onRender();
    
    void onKeyDown(SDL_Keycode key, Uint16 mod);
    
    void onKeyUp(SDL_Keycode key, Uint16 mod);
    
private:
    GameObject* background01;
    GameObject* background02;
    GameObject* background03;
    GameObject* background04;
    GameObject* background05;
    GameObject* background06;
    GameObject* background07;
    GameObject* background08;
    GameObject* background09;

    bool keyDown;
};

#endif	/* PARALLAXTEST_H */

