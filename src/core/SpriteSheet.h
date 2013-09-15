#ifndef SPRITESHEET_H
#define	SPRITESHEET_H

#include <json/json.h>
#include <SDL2/SDL.h>
#include <map>
#include <vector>
#include "Vector2D.h"
#include "SpriteAnimation.h"

class SpriteSheet {
public:
    SpriteSheet(const char * filePath);
    virtual ~SpriteSheet();
    
    SpriteAnimation *                   operator[](const char * animation);
    SpriteAnimation *                   getDefaultAnimation();
    SpriteAnimation *                   getAnimation(const char * animation);
    
    inline int                          getWidth() { return totalWidth; }
    inline int                          getHeight() { return totalHeight; }
    inline int                          getIndividualFrameWidth() { return frameWidth; }
    inline int                          getIndividualFrameHeight() { return frameHeight; }
    
    inline SDL_Texture *                getTexture() { return spriteSheet; }
    
    std::string                         toString();
private:
    SDL_Texture *                       spriteSheet;
    
    int                                 totalWidth;
    int                                 totalHeight;
    int                                 frameWidth;
    int                                 frameHeight;
    
    std::vector<SpriteAnimation *> *    animations;
    std::map<std::string, unsigned int> animationsMapper;
};

#endif	/* SPRITESHEET_H */

