#include "DebugState.h"

#include "../Game.h"
#include "../../core/ResourceManager.h"

DebugState::DebugState() {
    this->polesDude = NULL;
}

DebugState::~DebugState() {
}

void DebugState::onActivate() {
    this->polesDude = Game::createGameObject();
    unsigned int animations[1] = {1};
    Sprite * sprite = ResourceManager::loadImage("test_image", "images/test_image.png", 1, animations);
    this->polesDude->addComponent(new SpriteRendererComponent(sprite));
    
    Vector2D position(100, 100);
    this->polesDude->setPosition(position);
    this->polesDude->addComponent(new VelocityComponent(1.0f, 0.0f));
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

