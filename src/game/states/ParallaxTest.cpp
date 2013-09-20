#include "ParallaxTest.h"
#include "../Game.h"
#include "../../core/ResourceManager.h"

ParallaxTest ParallaxTest::instance;

ParallaxTest::ParallaxTest() {
    
}

ParallaxTest* ParallaxTest::getInstance() {
    return & instance;
}

void ParallaxTest::onActivate() {
    keyDown = false;

    background09 = Game::createGameObject();
    background08 = Game::createGameObject();
    background07 = Game::createGameObject();
    background06 = Game::createGameObject();
    background05 = Game::createGameObject();
    background04 = Game::createGameObject();
    background03 = Game::createGameObject();
    background02 = Game::createGameObject();
    background01 = Game::createGameObject();
    
    background09->addComponent(new components::SpriteRenderer(ResourceManager::getSpriteSheet("parallax-test/Layer09.png"), 0.0f));
    background08->addComponent(new components::SpriteRenderer(ResourceManager::getSpriteSheet("parallax-test/Layer08.png"), 0.1f));
    background07->addComponent(new components::SpriteRenderer(ResourceManager::getSpriteSheet("parallax-test/Layer07.png"), 0.2f));
    background06->addComponent(new components::SpriteRenderer(ResourceManager::getSpriteSheet("parallax-test/Layer06.png"), 0.3f));
    background05->addComponent(new components::SpriteRenderer(ResourceManager::getSpriteSheet("parallax-test/Layer05.png"), 0.4f));
    background04->addComponent(new components::SpriteRenderer(ResourceManager::getSpriteSheet("parallax-test/Layer04.png"), 0.5f));
    background03->addComponent(new components::SpriteRenderer(ResourceManager::getSpriteSheet("parallax-test/Layer03.png"), 1.0f));
    background02->addComponent(new components::SpriteRenderer(ResourceManager::getSpriteSheet("parallax-test/Layer02.png"), 0.8f));
    background01->addComponent(new components::SpriteRenderer(ResourceManager::getSpriteSheet("parallax-test/Layer01.png"), 1.0f));

    // Add movement to the clouds
    background06->addComponent(new components::Velocity(0.1f, 0.0f));
}

void ParallaxTest::onDeactivate() {
    Game::destroyGameObject(background01);
    Game::destroyGameObject(background02);
    Game::destroyGameObject(background03);
    Game::destroyGameObject(background04);
    Game::destroyGameObject(background05);
    Game::destroyGameObject(background06);
    Game::destroyGameObject(background07);
    Game::destroyGameObject(background08);
}

void ParallaxTest::onLoop() {
    
}

void ParallaxTest::onRender() {
    
}

void ParallaxTest::onKeyDown(SDL_Keycode key, Uint16 mod) {
    Vector2D force;
    switch (key) {
    case SDLK_LEFT:
        if (!keyDown) {
            force.setX(-0.5f);
            Game::getMainCameraObject()->addForce(force);
            keyDown = true;
        }
        break;

    case SDLK_RIGHT:
        if (!keyDown) {
            force.setX(0.5f);
            Game::getMainCameraObject()->addForce(force);
            keyDown = true;
        }
        break;

    case SDLK_ESCAPE:
        Game::exit();
        break;
    }
}

void ParallaxTest::onKeyUp(SDL_Keycode key, Uint16 mod) {
    switch (key) {
    case SDLK_LEFT:
        if (keyDown) {
            Game::getMainCameraObject()->resetForce();
            keyDown = false;
        }
        break;

    case SDLK_RIGHT:
        if (keyDown) {
            Game::getMainCameraObject()->resetForce();
            keyDown = false;
        }
        break;
    }
}
