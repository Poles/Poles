#ifndef SPRITE_H
#define	SPRITE_H

#include <SDL2/SDL_image.h>
#include <vector>

class Sprite {
public:
    Sprite(const char * imageFile, unsigned int rows = 1, unsigned int columns = 1);
    Sprite(const Sprite& orig);
    virtual ~Sprite();
private:
    SDL_Surface * image;
    std::vector<std::vector<SDL_Rect> >     frames;
};

#endif	/* SPRITE_H */

