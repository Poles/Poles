#include "DebugState.h"

#include "../Game.h"
#include "../../core/ResourceManager.h"
#include "../../core/Color.h"

/* STATIC VARIABLES */
DebugState DebugState::instance;
/*------------------*/


DebugState::DebugState() {
    
}

DebugState * DebugState::getInstance() {
    return & instance;
}

void DebugState::onActivate() {
    this->keyDown = false;
    
    this->background = Game::createGameObject();
    Sprite * sprite = NULL;
    sprite = ResourceManager::getSprite("Background");
    
    this->background->addComponent(new SpriteRendererComponent(sprite));
    Vector2D backgroundPosition(Game::getRenderingContextWidth() / 2, Game::getRenderingContextHeight() / 2);
    this->background->setPosition(backgroundPosition);
    
    this->zero = Game::createGameObject();
    this->zero->addComponent(new VelocityComponent());
    SpriteRendererComponent * component = (SpriteRendererComponent *)this->zero->addComponent(new SpriteRendererComponent(ResourceManager::getSprite("Zero")));
    component->setFrameRate(150);
    Vector2D zeroPosition(Game::getRenderingContextWidth() / 2, Game::getRenderingContextHeight() / 2);
    this->zero->setPosition(zeroPosition);
    
}

void DebugState::onDeactivate() {
    Game::destroyGameObject(this->background);
    Game::destroyGameObject(this->zero);

}

void DebugState::onLoop() {
    // If you need to calculate something each frame
}

void DebugState::onRender() {
    // If you need to render something in addition to normal rendering
}

void DebugState::onKeyDown(SDL_Keycode key, Uint16 mod) {
    Vector2D force;
    switch (key) {
        case SDLK_LEFT:
            if (!keyDown) {
                force.setX(-2.0f);
                this->zero->addForce(force);
                SpriteRendererComponent * sprite = (SpriteRendererComponent *)this->zero->getComponent<SpriteRendererComponent>();
                sprite->changeAnimation("Walk Left");
            }
            break;
            
        case SDLK_RIGHT:
            if (!keyDown) {
                force.setX(2.0f);
                this->zero->addForce(force);
                SpriteRendererComponent * sprite = (SpriteRendererComponent *)this->zero->getComponent<SpriteRendererComponent>();
                sprite->changeAnimation("Walk Right");
            }
            break;
            
        case SDLK_ESCAPE:
            Game::exit();
            break;
    }
    this->keyDown = true;
}

void DebugState::onKeyUp(SDL_Keycode key, Uint16 mod) {
    switch (key) {
        case SDLK_LEFT:
            this->zero->resetForce();
            break;
            
        case SDLK_RIGHT:
            this->zero->resetForce();
            break;
    }
    this->keyDown = false;
    SpriteRendererComponent * sprite = (SpriteRendererComponent *)this->zero->getComponent<SpriteRendererComponent>();
    sprite->changeAnimation("Stand");
}

