#ifndef SPRITESHEETRENDERERCOMPONENT_H
#define	SPRITESHEETRENDERERCOMPONENT_H

#include <Artemis/Artemis.h>
#include "../SpriteSheet.h"

class SpriteSheetRendererComponent : public artemis::Component {
public:
    SpriteSheetRendererComponent(SpriteSheet * spriteSheet);
    virtual ~SpriteSheetRendererComponent();
    
    void                        changeAnimation(const char * animation);
    
    void                        render(Vector2D & position);
    
    void                        updateAnimation();
    
    inline int                  getFrameWidth() { currentAnimation->getWidth(); }
    inline int                  getFrameHeight() { currentAnimation->getHeight(); }
    
private:
    SpriteSheet *               spriteSheet;
    
    SpriteAnimation *           currentAnimation;
    unsigned int                currentAnimationFrame;
    int                         timeLastUpdate;
    int                         frameIncrement;

};

#endif	/* SPRITESHEETRENDERERCOMPONENT_H */

