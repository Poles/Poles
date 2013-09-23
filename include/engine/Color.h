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

    Uint8                       red();
    Uint8                       green();
    Uint8                       blue();
    Uint8                       alpha();

    SDL_Color                   toSDLColor();
    Uint32                      toPixelValue(SDL_PixelFormat* format);

    const std::string           toString();

private:
    SDL_Color                   color;
};

namespace presetcolors {
    static Color Key("#ff00ff");      // This is used for alpha channel in BMP load
    static Color White("#ffffff");
    static Color Black("#000000");
    static Color Red("#ff0000");
    static Color Green("#00ff00");
    static Color Blue("#0000ff");
    static Color Purple("#7e1e9c");
    static Color ConsoleGreen("#15b01a");
    static Color ConsoleBlue("#0343df");
    static Color Pink("#ff81c0");
    static Color LightBlue("#95d9fc");
    static Color Teal("#029386");
    static Color Orange("#f97306");
    static Color LightGreen("#96f97b");
    static Color Magenta("#c20078");
    static Color Yellow("#ffff14");
    static Color SkyBlue("#75bbfd");
    static Color Grey("#929591");
    static Color LimeGreen("#89fe05");
    static Color LightPurple("#bf77f6");
    static Color Violet("#9a0eea");
    static Color DrakGreen("#033500");
    static Color Turquoise("#06c2ac");
    static Color Lavander("#c79fef");
    static Color DarkBlue("#00035b");
    static Color Tan("#d1b26f");
    static Color Cyan("00ffff");
    static Color Aqua("#13eac9");
    static Color Transparent(0,0,0,0);
}

#endif /* defined(__Poles__Color__) */
