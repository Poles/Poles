#include "DebugState.h"
#include <sstream>
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

    mountainAbove = Game::createGameObject();
    background = Game::createGameObject();
    mountainBig = Game::createGameObject();

    background->addComponent(new components::SpriteRenderer(ResourceManager::getSpriteSheet("background-mountain-sky.png"), 0, 0.0f));
    mountainBig->addComponent(new components::SpriteRenderer(ResourceManager::getSpriteSheet("background-mountain-behind.png"), 1, 0.3f));
    mountainAbove->addComponent(new components::SpriteRenderer(ResourceManager::getSpriteSheet("background-mountain-above.png"), 2, 0.5f));

    mountainAbove->setPosition(0, 750);
    
}

void DebugState::onDeactivate() {


}

void DebugState::onLoop() {
    // If you need to update something each frame

}

void DebugState::onRender() {
    // If you need to render something in addition to normal rendering
}

void DebugState::onKeyDown(SDL_Keycode key, Uint16 mod) {
    Vector2D force;
    switch (key) {
    case SDLK_LEFT:
        if (!keyDown) {
            Game::getMainCameraObject()->addForce(-1.0f, 0.0f);
            this->keyDown = true;
        }
        break;
            
    case SDLK_RIGHT:
        if (!keyDown) {
            Game::getMainCameraObject()->addForce(1.0f, 0.0f);
            this->keyDown = true;
        }
        break;

    case SDLK_UP:
        if (!keyDown) {
            Game::getMainCameraObject()->addForce(0.0f, -1.0f);
            this->keyDown = true;
        }
        break;

    case SDLK_DOWN:
        if (!keyDown) {
            Game::getMainCameraObject()->addForce(0.0f, 1.0f);
            this->keyDown = true;
        }
        break;
            
    case SDLK_ESCAPE:
        Game::exit();
        break;
    }
    
}

void DebugState::onKeyUp(SDL_Keycode key, Uint16 mod) {
    components::SpriteRenderer * sprite;
    
    switch (key) {
    case SDLK_LEFT:
    case SDLK_RIGHT:
    case SDLK_UP:
    case SDLK_DOWN:
        Game::getMainCameraObject()->resetForce();
        break;
    }
    this->keyDown = false;
    
}

