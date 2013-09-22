#include "SpriteRenderer.h"
#include "../../game/Game.h"
#include "ResourceManager.h"

using namespace components;

/**
 * 
 * @param spriteSheet
 */
SpriteRenderer::SpriteRenderer(SpriteSheet * spriteSheet, const int zIndex, const float parallax):
    Renderer(zIndex, parallax)
{
    this->spriteSheet = spriteSheet;
    this->currentAnimation = spriteSheet->getDefaultAnimation();
    this->currentAnimationFrame = 0;
    this->timeLastUpdate = SDL_GetTicks();
    this->frameIncrement = 1;
    this->parallaxIndex = parallax;
}

SpriteRenderer::SpriteRenderer(const char* spriteFile, const int zIndex, const float parallax):
    Renderer(zIndex, parallax)
{
    this->spriteSheet = ResourceManager::getSpriteSheet(spriteFile);
    this->currentAnimation = spriteSheet->getDefaultAnimation();
    this->currentAnimationFrame = 0;
    this->timeLastUpdate = SDL_GetTicks();
    this->frameIncrement = 1;
    this->parallaxIndex = parallax;
}

SpriteRenderer::~SpriteRenderer() {
    delete this->spriteSheet;
}

/**
 * 
 * @param animation
 */
void SpriteRenderer::changeAnimation(const char * animation) {
    this->currentAnimation = this->spriteSheet->getAnimation(animation);
    this->currentAnimationFrame = 0;
    this->frameIncrement = 1;
    this->timeLastUpdate = SDL_GetTicks();
}

/**
 * 
 * @param position
 */
void SpriteRenderer::render(Vector2D& position) {
    SDL_Rect spriteFrame = (* this->currentAnimation)[currentAnimationFrame];
    SDL_Rect renderFrame;
    
    renderFrame.x = position.x() - (this->currentAnimation->getWidth() / 2);
    renderFrame.y = position.y() - (this->currentAnimation->getHeight() / 2);
    renderFrame.w = this->currentAnimation->getWidth();
    renderFrame.h = this->currentAnimation->getHeight();
    
    SDL_RenderCopy(this->camera->getRenderer(), this->spriteSheet->getTexture(), & spriteFrame, & renderFrame);
    
    updateAnimation();
}

/**
 * 
 */
void SpriteRenderer::updateAnimation() {
    if (this->timeLastUpdate + this->currentAnimation->getFrameRate() > SDL_GetTicks()) {
        // We don't need to update
    } else {
        this->timeLastUpdate = SDL_GetTicks();
        
        this->currentAnimationFrame += this->frameIncrement;
        int numberOfFrames = this->currentAnimation->getNumberOfFrames();
        if (this->currentAnimation->isOscillating()) {
            if (this->frameIncrement > 0) {                
                if (this->currentAnimationFrame >= numberOfFrames -1) {
                    this->frameIncrement = (-1) * this->frameIncrement;
                }
            } else {
                if (this->currentAnimationFrame <= 0) {
                    this->frameIncrement = (-1) * this->frameIncrement;
                }
            }
        } else {
            if (this->currentAnimationFrame >= numberOfFrames) {
                this->currentAnimationFrame = 0;
            }
        }
    }
}

/**
 * @brief SpriteRenderer::getCurrentAnimationSurface
 * @return
 */
SDL_Surface* SpriteRenderer::getCurrentAnimationSurface() {
    SDL_Surface* surface = SDL_CreateRGBSurface(SDL_PIXELFORMAT_ARGB8888,
                         this->getFrameWidth(),
                         this->getFrameHeight(),
                         32,
                         0x00ff0000,
                         0x0000ff00,
                         0x000000ff,
                         0xff000000);

    SDL_Renderer* softwareRenderer = SDL_CreateSoftwareRenderer(surface);

    // Paint the pixels into the renderer, which will copy as well to the surface
    SDL_Rect spriteFrame = (* this->currentAnimation)[currentAnimationFrame];
    SDL_RenderCopy(softwareRenderer, this->spriteSheet->getTexture(), & spriteFrame, NULL);

    // Free resources used
    SDL_DestroyRenderer(softwareRenderer);

    return surface;
}

