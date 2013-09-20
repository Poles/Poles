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
    background09 = Game::createGameObject();
    background08 = Game::createGameObject();
    background07 = Game::createGameObject();
    background06 = Game::createGameObject();
    background05 = Game::createGameObject();
    background04 = Game::createGameObject();
    background03 = Game::createGameObject();
    background02 = Game::createGameObject();
    background01 = Game::createGameObject();
    
    background09->addComponent(new components::SpriteRenderer(ResourceManager::getSpriteSheet("parallax-test/Layer09.png")));
    background08->addComponent(new components::SpriteRenderer(ResourceManager::getSpriteSheet("parallax-test/Layer08.png")));
    background07->addComponent(new components::SpriteRenderer(ResourceManager::getSpriteSheet("parallax-test/Layer07.png")));
    background06->addComponent(new components::SpriteRenderer(ResourceManager::getSpriteSheet("parallax-test/Layer06.png")));
    background05->addComponent(new components::SpriteRenderer(ResourceManager::getSpriteSheet("parallax-test/Layer05.png")));
    background04->addComponent(new components::SpriteRenderer(ResourceManager::getSpriteSheet("parallax-test/Layer04.png")));
    background03->addComponent(new components::SpriteRenderer(ResourceManager::getSpriteSheet("parallax-test/Layer03.png")));
    background02->addComponent(new components::SpriteRenderer(ResourceManager::getSpriteSheet("parallax-test/Layer02.png")));
    background01->addComponent(new components::SpriteRenderer(ResourceManager::getSpriteSheet("parallax-test/Layer01.png")));
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
    switch (key) {
        case SDLK_ESCAPE:
            Game::exit();
            break;
    }
}

void ParallaxTest::onKeyUp(SDL_Keycode key, Uint16 mod) {
    
}
