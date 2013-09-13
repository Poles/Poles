#ifndef SPRITE_H
#define	SPRITE_H

#include <SDL2/SDL_image.h>
#include <vector>
#include <map>
#include "Vector2D.h"

class Sprite {
public:
    Sprite(const char * imageFile, unsigned int animations = 1, unsigned int * framesPerAnimation = NULL);
    virtual ~Sprite();
    
    inline SDL_Texture *                        getTexture() { return this->image; }
    
    inline int                                  getWidth() { return this->width; }
    inline int                                  getHeight() { return this->height; }
    
    inline int                                  getFrameWidth() { return this->widthPerFrame; }
    inline int                                  getFrameHeight() { return this->heightPerFrame; }
    
    bool                                        bindAnimation(const char * name, unsigned int animation);
    void                                        unbindAnimation(const char * name);
    int                                         getAnimationIndex(const char * name);
    const char *                                getAnimationName(const unsigned int animationIndex);
    SDL_Rect *                                  getFrameBox(const char * animation, unsigned int frame);
    int                                         getNumberOfFrames(const char * animation);
    
    void                                        showAnimationFramesInfo();
    void                                        showAnimationBindings();
    
private:
    SDL_Texture *                               image;
    std::vector<std::vector<SDL_Rect> >         frames;
    int                                         width;
    int                                         height;
    unsigned int                                widthPerFrame;
    unsigned int                                heightPerFrame;
    
    /* ANIMATION */
    std::map<std::string, unsigned int>        animationsBindingMap;
};

#endif	/* SPRITE_H */

