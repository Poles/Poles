#include "SpriteSheetRendererComponent.h"
#include "../../game/Game.h"

/**
 * 
 * @param spriteSheet
 */
SpriteSheetRendererComponent::SpriteSheetRendererComponent(SpriteSheet * spriteSheet)
{
    this->spriteSheet = spriteSheet;
    this->currentAnimation = spriteSheet->getDefaultAnimation();
    this->currentAnimationFrame = 0;
    this->timeLastUpdate = SDL_GetTicks();
    this->frameIncrement = 1;
}

SpriteSheetRendererComponent::~SpriteSheetRendererComponent() {
    
}

/**
 * 
 * @param animation
 */
void SpriteSheetRendererComponent::changeAnimation(const char * animation) {
    this->currentAnimation = this->spriteSheet->getAnimation(animation);
    this->currentAnimationFrame = 0;
    this->frameIncrement = 1;
    this->timeLastUpdate = SDL_GetTicks();
}

/**
 * 
 * @param position
 */
void SpriteSheetRendererComponent::render(Vector2D& position) {
    SDL_Rect spriteFrame = (* this->currentAnimation)[currentAnimationFrame];
    SDL_Rect renderFrame;
    
    renderFrame.x = position.x() - (this->currentAnimation->getWidth() / 2);
    renderFrame.y = position.y() - (this->currentAnimation->getHeight() / 2);
    renderFrame.w = this->currentAnimation->getWidth();
    renderFrame.h = this->currentAnimation->getHeight();
    
    SDL_RenderCopy(Game::currentRenderer(), this->spriteSheet->getTexture(), & spriteFrame, & renderFrame);
    
    updateAnimation();
}

/**
 * 
 */
void SpriteSheetRendererComponent::updateAnimation() {
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

