#include "SpriteRendererComponent.h"
#include <SDL2/SDL.h>
#include "../../game/Game.h"

SpriteRendererComponent::SpriteRendererComponent(Sprite * sprite) {
    this->sprite = sprite;
    this->currentAnimationFrame = 0;
    this->frameRate = 1000;     // 1 second per frame as default
    this->frameIncrement = 1;
    this->oldTime = SDL_GetTicks();
    this->oscillate = true;
    
    this->currentAnimation = sprite->getAnimationName(0);       // As default, the first animation
}

SpriteRendererComponent::~SpriteRendererComponent() {
}

/**
 * 
 * @param frameRate
 */
void SpriteRendererComponent::setFrameRate(int frameRate) {
    this->frameRate = frameRate;
}

void SpriteRendererComponent::changeAnimation(const char * name) {
    if (this->sprite->getAnimationIndex(name) != -1) {
        this->currentAnimation = name;
    }
}

void SpriteRendererComponent::updateAnimation() {
    if (this->oldTime + this->frameRate > SDL_GetTicks()) {
        return; // We don't need to update anything yet (I don't like using return this way, we need to change it)
    }
    
    this->oldTime = SDL_GetTicks();
    
    this->currentAnimationFrame += this->frameIncrement;
    
    if (this->oscillate) {
        // If we are advancing in the animation
        if (this->frameIncrement > 0) {
            int numberOfFrames = this->sprite->getNumberOfFrames(this->currentAnimation);
            if (this->currentAnimationFrame >= numberOfFrames - 1) {
                // We reverse the direction of the animation
                this->frameIncrement = (-1) * this->frameIncrement;
            }
        }else {
            if (currentAnimationFrame <= 0) {
                this->frameIncrement = (-1) * this->frameIncrement;
            }
        }
    } else {
        if (this->currentAnimationFrame >= this->sprite->getNumberOfFrames(this->currentAnimation)) {
            this->currentAnimationFrame = 0;
        }
    }
}

void SpriteRendererComponent::render(Vector2D & position) {
    SDL_Rect renderFrame;
    
    renderFrame.x = position.x() - (this->sprite->getFrameWidth() / 2);
    renderFrame.y = position.y() - (this->sprite->getFrameHeight() / 2);
    renderFrame.w = this->sprite->getFrameWidth();
    renderFrame.h = this->sprite->getFrameHeight();
    
    SDL_Rect * textureFrame;
    textureFrame = this->sprite->getFrameBox(this->currentAnimation, this->currentAnimationFrame);
    
    SDL_Texture * fullTexture = this->sprite->getTexture();
    
    SDL_RenderCopy(Game::currentRenderer(), fullTexture, textureFrame, & renderFrame);
    
    updateAnimation();
}
