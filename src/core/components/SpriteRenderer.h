#ifndef SPRITERENDERER_H
#define	SPRITERENDERER_H

#include <Artemis/Artemis.h>
#include "../SpriteSheet.h"
#include "Renderer.h"

namespace components{

class SpriteRenderer : public Renderer {
public:
    SpriteRenderer(SpriteSheet * spriteSheet, const int zIndex = 0, const float parallax = 1.0f);
    SpriteRenderer(const char* spriteFile, const int zIndex = 0, const float parallax = 1.0f);
    virtual ~SpriteRenderer();
    
    void                        changeAnimation(const char * animation);
    
    void                        render(Vector2D & position);
    
    void                        updateAnimation();
    
    inline int                  getFrameWidth() { currentAnimation->getWidth(); }
    inline int                  getFrameHeight() { currentAnimation->getHeight(); }

    SDL_Surface*                getCurrentAnimationSurface();
    
private:
    SpriteSheet *               spriteSheet;
    
    SpriteAnimation *           currentAnimation;
    unsigned int                currentAnimationFrame;
    int                         timeLastUpdate;
    int                         frameIncrement;

};

}

#endif	/* SPRITERENDERER_H */

