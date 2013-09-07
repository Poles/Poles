#ifndef TEXTRENDERERCOMPONENT_H
#define	TEXTRENDERERCOMPONENT_H

#include <string>
#include <Artemis/Component.h>
#include <SDL2/SDL_ttf.h>

class TextRendererComponent : public artemis::Component{
public:
    TextRendererComponent();
    TextRendererComponent(std::string text);
    virtual ~TextRendererComponent();
    
private:
    std::string text;
    TTF_Font * font;
};

#endif	/* TEXTRENDERERCOMPONENT_H */

