#ifndef __Poles__Game__
#define __Poles__Game__

#include <iostream>
#include <SDL.h>
#include "core/Circle.h"
#include "core/Line.h"

#define GAME_NAME "Poles"
#define FPS_MAX 60

class Game {
public:
    Game();
    ~Game();
    
    void start();
    
private:
    void initialize();
    void mainLoop();
    void update();
    void handleEvents();
    void render();
    void manageFPS();
    void countFSP();
    
private:
    SDL_Window* wnd;
    SDL_Renderer* rc;
    bool run;
    
    Uint32 timeLastFrame;   // Time mark of the last frame (ms)
    Uint32 timePerFrame;    // Time interval for each frame (ms)
    Uint32 frameSkip;       // Number of frames to skip from rendering when the game runs slower than expected
    
    Uint8 fps;  // Number of FPS
    Uint32 timeLastFPSRecord;  // Time mark of the last record of FPS (ms)
    
    /* FLAGS */
    bool showFPS;
    
    /* TEST */
    Circle* circle;
    Circle* evilCircle;
    Line* line;
    Line* normalLine;
};

#endif /* defined(__Poles__Game__) */
