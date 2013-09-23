#ifndef GAME_H
#define GAME_H

#include <string>
#include "engine/Window.h"
#include "engine/SceneManager.h"

#define ENGINE_MAX_FPS 60

class Game {
public:
    Game(std::string name);
    virtual ~Game();

    void                                createWindow(Uint16 w, Uint16 h, WindowMode mode);
    void                                createWindow();

    void                                start();

private:

    void                                mainLoop();

    void                                update();
    void                                render();
    void                                handleEvents();

    void                                updateDeltaTime();

    void                                countFramesPerSecond();
    void                                manageFramesPerSecond();

protected:
    std::string                         name;
    bool                                run;

private:
    // Delta time
    Uint32                              currentTime;    // Measures the number of ticks since the start of SDL
    Uint32                              oldTime;        // Number of ticks of the last update
    float                               deltaTime;      // Delta Time

    // Frames Per Second
    Uint32                              fpsCurrentTime;
    Uint32                              fpsOldTime;
    unsigned int                        fps;            // Number of frames rendered every second
    unsigned int                        fpsCounter;     // Current number of frames (inside this second)

    // Frame Skip
    Uint32                              frameSkipCurrentTime;
    Uint32                              frameSkipOldTime;
    unsigned int                        frameSkip;      // Frames to skip when the game is running slowly
    Uint32                              timePerFrame;

    /* Static Functions */
public:
    static void                         writeToConsole(std::string text);

    /* Static variables */
public:
    static Window*                      window;

    static systems::SceneManager        sceneManager;
};

#endif // GAME_H
