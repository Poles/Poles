#ifndef __Poles__Game__
#define __Poles__Game__

#include <iostream>
#include <SDL2/SDL.h>
#include <Artemis/Artemis.h>
#include "../core/systems/MovementSystem.h"
#include "../core/systems/RenderingSystem.h"
#include "../core/systems/TextRenderingSystem.h"
#include "../core/GameObject.h"

#define GAME_NAME "Poles"
#define FPS_MAX 60

class Game {
public:
    Game();
    ~Game();
    
    void                                start();
    
    static void                         exit();
    
    static GameObject *                 createGameObject();
    static void                         destroyGameObject(GameObject * object);
    
    static SDL_Renderer *               currentRenderer();
    
    static inline int                   getRenderingContextWidth() { return renderingContextWidth; }
    static inline int                   getRenderingContextHeight() { return renderingContextHeight; }
    
private:
    void                                initialize();
    void                                loadResources();
    void                                mainLoop();
    void                                update();
    void                                handleEvents();
    void                                render();
    
    void                                manageFPS();
    void                                countFSP();    
    
private:
    SDL_Window* wnd;
    static SDL_Renderer *               renderer;
    
    static int                          renderingContextWidth;
    static int                          renderingContextHeight;
    
    static bool                         run;
    
    /* ARTEMIS */
    static artemis::World               world;
    static artemis::SystemManager *     systemManager;
    static artemis::EntityManager *     entityManager;
    
    MovementSystem *                    movementSystem;
    RenderingSystem *                   renderingSystem;
    TextRenderingSystem *               textRenderingSystem;
    
    /* FPS */
    Uint32                              timeLastFrame;   // Time mark of the last frame (ms)
    Uint32                              timePerFrame;    // Time interval for each frame (ms)
    Uint32                              frameSkip;       // Number of frames to skip from rendering when the game runs slower than expected
    
    Uint8                               fps;  // Number of FPS
    Uint32                              timeLastFPSRecord;  // Time mark of the last record of FPS (ms)
    
    /* FLAGS */
    bool                                showFPS;
};

#endif /* defined(__Poles__Game__) */
