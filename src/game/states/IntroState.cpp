#include "IntroState.h"
#include "../Game.h"
#include "../../core/ResourceManager.h"
#include <iostream>

IntroState IntroState::instance;

IntroState::IntroState() {
    
}

void IntroState::onActivate() {
    int width = Game::getRenderingContextWidth();
    int height = Game::getRenderingContextHeight();
    
    Vector2D centerPosition(width / 2, height / 2);
    Vector2D mountainsInitPosition = centerPosition - Vector2D(0, height / 2);
    
    this->backgroundMountainSky = Game::createGameObject();
    this->backgroundMountainSky->addComponent(new SpriteRendererComponent(ResourceManager::getSprite("background-mountain-sky")));
    this->backgroundMountainSky->setPosition(centerPosition);
    
    this->backgroundMountainBehind = Game::createGameObject();
    this->backgroundMountainBehind->addComponent(new SpriteRendererComponent(ResourceManager::getSprite("background-mountain-behind")));
    this->backgroundMountainBehind->addComponent(new VelocityComponent());
    this->backgroundMountainBehind->setPosition(mountainsInitPosition);
    
    this->backgroundMountainAbove = Game::createGameObject();
    SpriteRendererComponent * component = (SpriteRendererComponent *)this->backgroundMountainAbove->addComponent(new SpriteRendererComponent(ResourceManager::getSprite("background-mountain-above")));
    this->backgroundMountainAbove->addComponent(new VelocityComponent());
    unsigned int mountainHeight = component->getFrameHeight();
    
    Vector2D aboveMountainPosition = mountainsInitPosition + Vector2D(0.0f, (mountainHeight / 2) + 150.0f);
    this->backgroundMountainAbove->setPosition(aboveMountainPosition);
    
    this->polesDude = Game::createGameObject();
    this->polesDude->setParent(this->backgroundMountainAbove);
    Vector2D polesDudePosition(0.0f, (-1.0f) * ((float)mountainHeight / 2.0f) - 4.0f);
    this->polesDude->setPosition(polesDudePosition);
    
    this->polesDude->addComponent(new SpriteRendererComponent(ResourceManager::getSprite("poles_dude")));
    
    this->initTime = SDL_GetTicks();
    this->durationTime = 8000;
    
    Vector2D fastMovement(0.0f, 0.35f);
    Vector2D slowMovement(0.0f, 0.10f);
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
}
