#include "IntroState.h"
#include "../Game.h"
#include "../../core/ResourceManager.h"
#include <iostream>

IntroState IntroState::instance;

IntroState::IntroState() {
    
}

void IntroState::onActivate() {
    /* FLAGS */
    buttonPressed = false;
    /*-------*/
    
    int width = Game::getRenderingContextWidth();
    int height = Game::getRenderingContextHeight();
    
    Vector2D centerPosition(width / 2, height / 2);
    Vector2D mountainsInitPosition = centerPosition - Vector2D(0, height / 2 - 500);
    
    this->backgroundMountainSky = Game::createGameObject();
    this->backgroundMountainSky->addComponent(new SpriteSheetRendererComponent(ResourceManager::getSpriteSheet("background-mountain-sky")));
    this->backgroundMountainSky->setPosition(centerPosition);
    
    this->backgroundMountainBehind = Game::createGameObject();
    this->backgroundMountainBehind->addComponent(new SpriteSheetRendererComponent(ResourceManager::getSpriteSheet("background-mountain-behind")));
    this->backgroundMountainBehind->addComponent(new VelocityComponent());
    this->backgroundMountainBehind->setPosition(mountainsInitPosition);
    
    this->backgroundMountainAbove = Game::createGameObject();
    SpriteSheetRendererComponent * component = (SpriteSheetRendererComponent *)this->backgroundMountainAbove->addComponent(new SpriteSheetRendererComponent(ResourceManager::getSpriteSheet("background-mountain-above")));
    this->backgroundMountainAbove->addComponent(new VelocityComponent());
    unsigned int mountainHeight = component->getFrameHeight();
    
    Vector2D aboveMountainPosition = mountainsInitPosition + Vector2D(0.0f, (mountainHeight / 2) + 150.0f);
    this->backgroundMountainAbove->setPosition(aboveMountainPosition);
    
    this->polesDude = Game::createGameObject();
    this->polesDude->addComponent(new SpriteSheetRendererComponent(ResourceManager::getSpriteSheet("poles_dude")));
    this->polesDude->setParent(this->backgroundMountainAbove);
    this->polesDude->addComponent(new VelocityComponent(0.0f, 0.0f));
    Vector2D polesDudePosition(0.0f, (-1.0f) * ((float)mountainHeight / 2.0f) - 4.0f);
    this->polesDude->setPosition(polesDudePosition);
    
    
    this->initTime = SDL_GetTicks();
    this->durationTime = 8000;
    
    Vector2D fastMovement(0.0f, 0.30f);
    Vector2D slowMovement(0.0f, 0.09f);
    this->backgroundMountainAbove->addForce(fastMovement);
    this->backgroundMountainBehind->addForce(slowMovement);
    
    /* TITLE */
    this->showTitleKeyTime = 4000;
    this->titleColor = Color("#ffffff");
    this->titleColor.setAlpha(0);
    this->title = Game::createGameObject();
    TextRendererComponent * textComponent = (TextRendererComponent *)this->title->addComponent(new TextRendererComponent("Poles", "Mojang"));
    Vector2D titlePosition(Game::getRenderingContextWidth() / 2.0f, 40.0f);
    this->title->setPosition(titlePosition);
    textComponent->setForegroundColor(this->titleColor);
}

void IntroState::onDeactivate() {
    
}

void IntroState::onLoop() {
    if (SDL_GetTicks() + this->initTime >= this->durationTime) {
        this->backgroundMountainAbove->resetForce();
        this->backgroundMountainBehind->resetForce();
    }
    
    if (this->titleColor.alpha() < 255) {
        if (SDL_GetTicks() + this->initTime >= this->showTitleKeyTime) {
            this->titleColor.setAlpha( this->titleColor.alpha() + 1);
        }
    }    
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
    
    if (buttonPressed == false) {
        switch (key) {
            case SDLK_LEFT:
                this->polesDude->addForce(-1.0f, 0.0f);
                break;
                
            case SDLK_RIGHT:
                this->polesDude->addForce(1.0f, 0.0f);
                break;
        }
        buttonPressed = true;
    }
}

void IntroState::onKeyUp(SDL_Keycode key, Uint16 mod) {
    buttonPressed = false;
    this->polesDude->resetForce();
}
