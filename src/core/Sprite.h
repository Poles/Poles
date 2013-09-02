#ifndef SPRITE_H
#define	SPRITE_H

#include <SDL2/SDL_image.h>
#include <vector>
#include <map>
#include "Vector2D.h"

class Sprite {
public:
    Sprite(const char * imageFile, unsigned int animations = 1, unsigned int * framesPerAnimation = NULL);
    Sprite(const Sprite& orig);
    virtual ~Sprite();
    
    SDL_Rect *                                  getCurrentFrameBox();
    SDL_Texture *                               getTexture();
    
    int                                         getWidth();
    int                                         getHeight();
    
    bool                                        bindAnimation(const char * name, unsigned int animation);
    void                                        unbindAnimation(const char * name);
    void                                        setAnimation(const char * name);
    
    void                                        showAnimationFramesInfo();
    
    void                                        render(Vector2D & position);
    
private:
    void                                        updateAnimation();
    
private:
    SDL_Texture *                               image;
    std::vector<std::vector<SDL_Rect> >         frames;
    int                                         width;
    int                                         height;
    unsigned int                                widthPerFrame;
    unsigned int                                heightPerFrame;
    
    /* ANIMATION */
    unsigned int                                currentAnimation;
    unsigned int                                currentFrame;
    std::map<const char *, unsigned int>        animationsBindingMap;
    int                                         frameRate;      // How many miliseconds do we need to change to the next frame
    int                                         oldTime;
    int                                         frameIncrement;
    
    /* FLAGS */
    bool                                        oscillate;
};

#endif	/* SPRITE_H */

