#ifndef SPRITERENDERERCOMPONENT_H
#define	SPRITERENDERERCOMPONENT_H

#include <Artemis/Artemis.h>
#include "../Sprite.h"

class SpriteRendererComponent : public artemis::Component{
public:
    SpriteRendererComponent(Sprite * sprite);
    virtual ~SpriteRendererComponent();
    
    void                                setFrameRate(int frameRate);
    void                                changeAnimation(const char * name);    
    
    void                                render(Vector2D & position);
    
    inline unsigned int                 getFrameWidth() { return sprite->getFrameWidth(); }
    inline unsigned int                 getFrameHeight() { return sprite->getFrameHeight(); }
    
private:
    void                                updateAnimation();
    
private:
    Sprite *                            sprite;
    
    /* ANIMATION */
    const char *                        currentAnimation;
    int                                 currentAnimationFrame;
    int                                 frameRate;
    int                                 oldTime;
    int                                 frameIncrement;
    bool                                oscillate;
};

#endif	/* SPRITERENDERERCOMPONENT_H */

