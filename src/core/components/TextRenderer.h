#ifndef TEXTRENDERERCOMPONENT_H
#define	TEXTRENDERERCOMPONENT_H

#include <string>
#include <Artemis/Component.h>
#include <SDL2/SDL_ttf.h>
#include "../Color.h"
#include "../Vector2D.h"
#include "Renderer.h"

#define TEXT_DEFAULT_FONT "Mojang"

namespace components {

class TextRenderer : public Renderer{
public:
    TextRenderer();
    TextRenderer(std::string text, const char * fontName);
    virtual ~TextRenderer();
    
    void                                setBackgroundColor(Color & color);
    void                                setForegroundColor(Color & color);
    
    inline Color &                      getBackgroundColor() { return this->backgroundColor; }
    inline Color &                      getForgroundColor() { return this->foregroundColor; }
    
    void                                setFont(const char * fontName);
    
    void                                setPointSize(int pointSize);

    inline void                         setText(std::string text) { this->text = text; }
    
    void                                render(Vector2D & position);
    
private:
    std::string                         text;
    TTF_Font *                          font;
    unsigned int                        pointSize;
    Color                               foregroundColor;
    Color                               backgroundColor;
};

}
#endif	/* TEXTRENDERERCOMPONENT_H */

