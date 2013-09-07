#include "DebugState.h"

#include "../Game.h"
#include "../../core/ResourceManager.h"

DebugState DebugState::instance;

DebugState::DebugState() {
}

DebugState::~DebugState() {
}

/**
 * 
 * @return 
 */
DebugState * DebugState::getInstance() {
    return & instance;
}

void DebugState::onActivate() {
    this->polesDude = Game::createGameObject();
    this->polesDude->addComponent(new VelocityComponent());
    Vector2D position(20,20);
    this->polesDude->setPosition(position);
    
    unsigned int animations[1] = {2};

    Sprite * sprite = ResourceManager::getSprite("poles_dude");
    this->polesDude->addComponent(new SpriteRendererComponent(sprite));
}

void DebugState::onDeactivate() {
    Game::destroyGameObject(this->polesDude);
    ResourceManager::deleteImage("poles_dude");
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
            force.setX(-1.0f);
            this->polesDude->addForce(force);
            break;
            
        case SDLK_RIGHT:
            force.setX(1.0f);
            this->polesDude->addForce(force);
            break;
            
        case SDLK_ESCAPE:
            Game::exit();
            break;
    }
}

void DebugState::onKeyUp(SDL_Keycode key, Uint16 mod) {
    Vector2D force;
    switch (key) {
        case SDLK_LEFT:
            force.setX(1.0f);
            this->polesDude->addForce(force);
            break;
            
        case SDLK_RIGHT:
            force.setX(-1.0f);
            this->polesDude->addForce(force);
            break;
    }
}

