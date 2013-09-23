#ifndef GAME_H
#define GAME_H

#include <string>
#include "engine/Window.h"

class Game {
public:
    Game(std::string name);
    virtual ~Game();

    void                                createWindow(Uint16 w, Uint16 h, WindowMode mode);
    void                                createWindow();

    void                                start();

private:
    std::string                         name;

    /* Static Functions */
public:
    static void                         writeToConsole(std::string text);

    /* Static variables */
public:
    static Window*                      window;
};

#endif // GAME_H
