#include "IntroState.h"
#include "../Game.h"
#include "../../core/ResourceManager.h"
#include <iostream>

IntroState IntroState::instance;

IntroState::IntroState() {
    
}

void IntroState::onActivate() {
    object = Game::createGameObject();
    Sprite * sprite = ResourceManager::getSprite("test_image");
    
    object->addComponent(new SpriteRendererComponent(sprite));
    object->addComponent(new VelocityComponent(1.0f, 0.0f));
}

void IntroState::onDeactivate() {
    
}

void IntroState::onLoop() {
    
}

void IntroState::onRender() {
    
}

IntroState * IntroState::getInstance() {
    return & instance;
}

void IntroState::onKeyDown(SDL_Keycode key, Uint16 mod) {
    if (key == SDLK_ESCAPE) {
        Game::exit();
    }
}
