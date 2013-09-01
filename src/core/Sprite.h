#ifndef SPRITE_H
#define	SPRITE_H

#include <SDL2/SDL_image.h>
#include <vector>

class Sprite {
public:
    Sprite(const char * imageFile, unsigned int rows = 1, unsigned int columns = 1);
    Sprite(const Sprite& orig);
    virtual ~Sprite();
    
    SDL_Rect *                                  currentFrameBox();
    SDL_Texture *                               texture();
    
    int                                         getWidth();
    int                                         getHeight();
    
private:
    SDL_Texture *                               image;
    std::vector<std::vector<SDL_Rect> >         frames;
    int                                         width;
    int                                         height;
    
    /* ANIMATION */
    unsigned int                                currentAnimation;
    unsigned int                                currentFrame;
    
    /* FLAGS */
    bool                                        oscillate;
};

#endif	/* SPRITE_H */

