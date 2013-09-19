#ifndef GAMESTATE_H
#define	GAMESTATE_H

#include "EventListener.h"

class GameState : public EventListener {
public:
    GameState();
public:
    virtual void onActivate() = 0;
    
    virtual void onDeactivate() = 0;
    
    virtual void onLoop() = 0;
    
    virtual void onRender() = 0;

};

#endif	/* GAMESTATE_H */

