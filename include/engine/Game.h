#ifndef GAME_H
#define GAME_H

#include <string>
#include "engine/Window.h"

#define ENGINE_MAX_FPS 60

class Game {
public: // methods
    Game(std::string name);
    virtual ~Game();

    void                                createWindow(Uint16 w, Uint16 h, WindowMode mode);
    void                                createWindow();
    void                                start();

private: // methods
    void                                mainLoop();
    void                                update();
    void                                render();
    void                                handleEvents();
    void                                updateDeltaTime();
    void                                countFramesPerSecond();
    void                                manageFramesPerSecond();

protected: // methods
    std::string                         name;
    bool                                run;

private: // attributes
    // Delta time
    Uint32                              currentTime;    // Measures the number of ticks since the start of SDL
    Uint32                              oldTime;        // Number of ticks on last update
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

public: // static methods
    static void                         writeToConsole(std::string text);

public: // static attributes
    static Window*                      window;
};

#endif // GAME_H
