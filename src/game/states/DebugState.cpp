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
    
    this->background = Game::createGameObject();
    SpriteSheet * sprite = NULL;
    sprite = ResourceManager::getSpriteSheet("background-mountain-sky.png");
    
    this->background->addComponent(new components::SpriteRenderer(sprite));
    Vector2D backgroundPosition(Game::getRenderingContextWidth() / 2, Game::getRenderingContextHeight() / 2);
    //Vector2D backgroundPosition(0,0);
    this->background->setPosition(backgroundPosition);
    
    this->zero = Game::createGameObject();
    this->zero->addComponent(new components::Velocity());
    components::SpriteRenderer * component = (components::SpriteRenderer *)this->zero->addComponent(new components::SpriteRenderer(ResourceManager::getSpriteSheet("zero")));
    //Vector2D zeroPosition(Game::getRenderingContextWidth() / 2, Game::getRenderingContextHeight() / 2);
    Vector2D zeroPosition(Game::getRenderingContextWidth() / 2, Game::getRenderingContextHeight() / 2);
    this->zero->setPosition(zeroPosition);

    sprite = ResourceManager::getSpriteSheet("zero");

    // Set the camera to track Zero's position
    Game::getMainCameraObject()->setPosition(Game::getRenderingContextWidth() / 2, Game::getRenderingContextHeight() / 2);
    Game::getMainCameraObject()->setParent(zero);

    // Debug info in screen
    debugInfo = Game::createGameObject();

    text = (components::TextRenderer*)debugInfo->addComponent(new components::TextRenderer(Game::getMainCameraObject()->getPosition().toString(), "Mojang"));
    debugInfo->setParent(zero);
    Vector2D debugInfoRelativePosition(0,50);
    debugInfo->setPosition(debugInfoRelativePosition);

    text->setBackgroundColor(presetColors::COLOR_BLACK);
    text->setForegroundColor(presetColors::COLOR_WHITE);

    zeroInfo = Game::createGameObject();
    zeroText = (components::TextRenderer*)zeroInfo->addComponent(new components::TextRenderer(Game::getMainCameraObject()->getPosition().toString(), "Mojang"));

    zeroText->setBackgroundColor(presetColors::COLOR_PURPLE);
    zeroText->setForegroundColor(presetColors::COLOR_WHITE);
    zeroInfo->setParent(zero);
    zeroInfo->setPosition(0,-50);
}

void DebugState::onDeactivate() {
    Game::destroyGameObject(this->background);
    Game::destroyGameObject(this->zero);

}

void DebugState::onLoop() {
    // If you need to update something each frame
    std::stringstream zeroStream;

    zeroStream << "Zero = " << zero->getPosition().toString();

    zeroText->setText(zeroStream.str());

    std::stringstream cameraStream;

    cameraStream << "Camera = " << Game::getMainCameraObject()->getPosition().toString();
    
    text->setText(cameraStream.str());
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
                components::SpriteRenderer * sprite = (components::SpriteRenderer *)this->zero->getComponent<components::SpriteRenderer>();
                sprite->changeAnimation("Walk Left");
                this->keyDown = true;
            }
            break;
            
        case SDLK_RIGHT:
            if (!keyDown) {
                force.setX(3.0f);
                this->zero->addForce(force);
                components::SpriteRenderer * sprite = (components::SpriteRenderer *)this->zero->getComponent<components::SpriteRenderer>();
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
    components::SpriteRenderer * sprite;
    
    switch (key) {
        case SDLK_LEFT:
            this->zero->resetForce();
            sprite = (components::SpriteRenderer *)this->zero->getComponent<components::SpriteRenderer>();
            sprite->changeAnimation("Stand Left");
            break;
            
        case SDLK_RIGHT:
            this->zero->resetForce();
            sprite = (components::SpriteRenderer *)this->zero->getComponent<components::SpriteRenderer>();
            sprite->changeAnimation("Stand Right");
            break;
    }
    this->keyDown = false;
    
}

