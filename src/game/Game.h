#ifndef __Poles__Game__
#define __Poles__Game__

#include <iostream>
#include <SDL2/SDL.h>
#include <Artemis.h>
#include "../core/Circle.h"
#include "../core/Line.h"
#include "../core/systems/MovementSystem.h"
#include "../core/GameObject.h"

#define GAME_NAME "Poles"
#define FPS_MAX 60

class Game {
public:
    Game();
    ~Game();
    
    void start();
    
    static GameObject * createGameObject();
    static void destroyGameObject(GameObject * object);
    
private:
    void initialize();
    void mainLoop();
    void update();
    void handleEvents();
    void render();
    void manageFPS();
    void countFSP();
    
    static SDL_Renderer * currentRenderer();
    
private:
    SDL_Window* wnd;
    static SDL_Renderer* rc;
    bool run;
    
    /* ARTEMIS */
    static artemis::World world;
    static artemis::SystemManager * systemManager;
    static artemis::EntityManager * entityManager;
    
    MovementSystem * movementSystem;
    
    /* FPS */
    Uint32 timeLastFrame;   // Time mark of the last frame (ms)
    Uint32 timePerFrame;    // Time interval for each frame (ms)
    Uint32 frameSkip;       // Number of frames to skip from rendering when the game runs slower than expected
    
    Uint8 fps;  // Number of FPS
    Uint32 timeLastFPSRecord;  // Time mark of the last record of FPS (ms)
    
    /* FLAGS */
    bool showFPS;
};

#endif /* defined(__Poles__Game__) */
