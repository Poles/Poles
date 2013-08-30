#ifndef __Poles__Color__
#define __Poles__Color__

#include <iostream>
#include <SDL2/SDL.h>

class Color{
public:
    Color();
    Color(int r, int g, int b, int a);
    Color(const char* hexString, const Uint8 alpha = 255);
    
    inline void                 setRed(int value);
    inline void                 setGreen(int value);
    inline void                 setBlue(int value);
    inline void                 setAlpha(int value);
    
    const Uint8                 red();
    const Uint8                 green();
    const Uint8                 blue();
    const Uint8                 alpha();
    
    SDL_Color                   toSDLColor();
    Uint32                      toPixelValue(SDL_PixelFormat* format);
    
    const std::string           toString();
    
private:
    SDL_Color                   color;
    Uint8                       _a;
};

#endif /* defined(__Poles__Color__) */
