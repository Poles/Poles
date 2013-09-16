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
    SpriteSheet * sprite = NULL;
    sprite = ResourceManager::getSpriteSheet("background-mountain-sky.png");
    
    this->background->addComponent(new SpriteSheetRendererComponent(sprite));
    Vector2D backgroundPosition(Game::getRenderingContextWidth() / 2, Game::getRenderingContextHeight() / 2);
    this->background->setPosition(backgroundPosition);
    
    this->zero = Game::createGameObject();
    this->zero->addComponent(new VelocityComponent());
    SpriteSheetRendererComponent * component = (SpriteSheetRendererComponent *)this->zero->addComponent(new SpriteSheetRendererComponent(ResourceManager::getSpriteSheet("zero")));
    Vector2D zeroPosition(Game::getRenderingContextWidth() / 2, Game::getRenderingContextHeight() / 2);
    this->zero->setPosition(zeroPosition);

    sprite = ResourceManager::getSpriteSheet("zero");
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
                force.setX(-3.0f);
                this->zero->addForce(force);
                SpriteSheetRendererComponent * sprite = (SpriteSheetRendererComponent *)this->zero->getComponent<SpriteSheetRendererComponent>();
                sprite->changeAnimation("Walk Left");
                this->keyDown = true;
            }
            break;
            
        case SDLK_RIGHT:
            if (!keyDown) {
                force.setX(3.0f);
                this->zero->addForce(force);
                SpriteSheetRendererComponent * sprite = (SpriteSheetRendererComponent *)this->zero->getComponent<SpriteSheetRendererComponent>();
                sprite->changeAnimation("Walk Right");
                this->keyDown = true;
            }
            break;
            
        case SDLK_ESCAPE:
            Game::exit();
            break;
    }
    
}

void DebugState::onKeyUp(SDL_Keycode key, Uint16 mod) {
    SpriteSheetRendererComponent * sprite;
    
    switch (key) {
        case SDLK_LEFT:
            this->zero->resetForce();
            sprite = (SpriteSheetRendererComponent *)this->zero->getComponent<SpriteSheetRendererComponent>();
            sprite->changeAnimation("Stand Left");
            break;
            
        case SDLK_RIGHT:
            this->zero->resetForce();
            sprite = (SpriteSheetRendererComponent *)this->zero->getComponent<SpriteSheetRendererComponent>();
            sprite->changeAnimation("Stand Right");
            break;
    }
    this->keyDown = false;
    
}

