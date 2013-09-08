#ifndef __Poles__Color__
#define __Poles__Color__

#include <iostream>
#include <SDL2/SDL.h>



class Color{
public:
    Color();
    Color(int r, int g, int b, int a);
    Color(const char* hexString, const Uint8 alpha = 255);
    Color(const Color & other);
    
    void                        setRed(int value);
    void                        setGreen(int value);
    void                        setBlue(int value);
    void                        setAlpha(int value);
    
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

namespace presetColors {
    static Color COLOR_KEY("#ff00ff");      // This is used for alpha channel in BMP load
    static Color COLOR_WHITE("#ffffff");
    static Color COLOR_BLACK("#000000");
    static Color COLOR_RED("#ff0000");
    static Color COLOR_GREEN("#00ff00");
    static Color COLOR_BLUE("#0000ff");
    static Color COLOR_PURPLE("#7e1e9c");
    static Color COLOR_CONSOLE_GREEN("#15b01a");
    static Color COLOR_CONSOLE_BLUE("#0343df");
    static Color COLOR_PINK("#ff81c0");
    static Color COLOR_LIGHT_BLUE("#95d9fc");
    static Color COLOR_TEAL("#029386");
    static Color COLOR_ORANGE("#f97306");
    static Color COLOR_LIGHT_GREEN("#96f97b");
    static Color COLOR_MAGENTA("#c20078");
    static Color COLOR_YELLOW("#ffff14");
    static Color COLOR_SKY_BLUE("#75bbfd");
    static Color COLOR_GREY("#929591");
    static Color COLOR_LIME_GREEN("#89fe05");
    static Color COLOR_LIGHT_PURPLE("#bf77f6");
    static Color COLOR_VIOLET("#9a0eea");
    static Color COLOR_DARK_GREEN("#033500");
    static Color COLOR_TURQUOISE("#06c2ac");
    static Color COLOR_LAVANDER("#c79fef");
    static Color COLOR_DARK_BLUE("#00035b");
    static Color COLOR_TAN("#d1b26f");
    static Color COLOR_CYAN("00ffff");
    static Color COLOR_AQUA("#13eac9");
    static Color COLOR_TRANSPARENT(0,0,0,0);
}

#endif /* defined(__Poles__Color__) */
