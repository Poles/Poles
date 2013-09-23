#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <string>
#include "engine/Color.h"

typedef enum {
    Fullscreen,
    Windowed
} WindowMode;

class Window {
public:
    Window(std::string title);
    Window(std::string title, Uint16 w, Uint16 h, WindowMode mode, Color bg = presetcolors::LightBlue);
    virtual ~Window();

    void                                setTitle(std::string title);
    void                                changeResolution(Uint16 w, Uint16 h);
    void                                changeMode(WindowMode mode);

    inline Uint16                       getWidth() { return width; }
    inline Uint16                       getHeight() { return height; }
    inline WindowMode                   getMode() { return mode; }
    inline Color                        getBackgroundColor() { return bgColor; }

    inline SDL_Renderer*                getRenderer() { return renderer; }

    inline void                         clear() { SDL_RenderClear(this->renderer); }
    inline void                         draw() { SDL_RenderPresent(this->renderer); }

private:
    void                                showDisplayModeInfo(SDL_DisplayMode &mode);

private:
    std::string                         title;      // Title the window will show
    Uint16                              width;      // Resolution width
    Uint16                              height;     // Resolution height
    WindowMode                          mode;       // View mode of the window

    Color                               bgColor;    // Color the window will use to clean the renderer

    SDL_Window*                         window;     // Window

    SDL_Renderer*                       renderer;   // Renderer that will draw into the window
};

#endif // WINDOW_H
