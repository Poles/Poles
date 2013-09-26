#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include "Vector2D.h"

class SpriteAnimation {
public:
    SpriteAnimation();
    SpriteAnimation(
            std::string name,
            unsigned int animationIndex,
            unsigned int widthPerFrame,
            unsigned int heightPerFrame,
            unsigned int numberOfFrames,
            unsigned int frameRate = 200,
            bool oscillate = false);
    virtual ~SpriteAnimation();
    
    SDL_Rect                    operator[](const unsigned int frameIndex);
    
    std::string                 toString();
    
    inline std::string          getName() { return name; }
    inline int                  getFrameRate() { return frameRate; }
    inline int                  isOscillating() { return oscillate; }
    inline int                  getNumberOfFrames() { return frames->size(); }
    inline int                  getWidth() { return frameWidth; }
    inline int                  getHeight() { return frameHeight; }
    
private:
    std::string                 name;
    
    unsigned int                frameWidth;
    unsigned int                frameHeight;
    
    std::vector<Vector2D> *     frames;
    
    unsigned int                frameRate;
    bool                        oscillate;
};