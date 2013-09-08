#include "DebugState.h"

#include "../Game.h"
#include "../../core/ResourceManager.h"
#include "../../core/Color.h"

DebugState::DebugState() {
    this->polesDude = NULL;
    this->keyDown = false;
}

DebugState::~DebugState() {
}

void DebugState::onActivate() {
    this->polesDude = Game::createGameObject();
    Sprite * sprite = ResourceManager::getSprite("poles_dude");
    this->polesDude->addComponent(new SpriteRendererComponent(sprite));
    
    Vector2D position(100, 100);
    this->polesDude->setPosition(position);
    this->polesDude->addComponent(new VelocityComponent(0.0f, 0.0f));
    
    /* TEXT */
    this->text = Game::createGameObject();
    TextRendererComponent * component = (TextRendererComponent *)this->text->addComponent(new TextRendererComponent("Test text!", "Mojang"));
    component->setForegroundColor(presetColors::COLOR_WHITE);
    position.setX(200);
    position.setY(20);
    this->text->setPosition(position);
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
            if (!keyDown) {
                force.setX(-1.0f);
                this->polesDude->addForce(force);
            }
            break;
            
        case SDLK_RIGHT:
            if (!keyDown) {
                force.setX(1.0f);
                this->polesDude->addForce(force);
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
            this->polesDude->resetForce();
            break;
            
        case SDLK_RIGHT:
            this->polesDude->resetForce();
            break;
    }
    this->keyDown = false;
}

