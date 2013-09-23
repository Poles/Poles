#include "TestScene.h"

#include "engine/Game.h"

TestScene::TestScene() : Scene("Test Scene") {

}

void TestScene::onActivate() {
    createGameObject("Test01");
}

void TestScene::onDeactivate() {
    destroyGameObject("Test01");
}

void TestScene::onLoop() {
    std::cout << "There is " << this->world->getEntityManager()->getEntityCount() << " entities in this Scene." << std::endl;
}

void TestScene::onRender() {

}

void TestScene::onKeyDown(SDL_Keycode key, Uint16 mod) {
    switch (key) {
    case SDLK_ESCAPE:
        Game::terminate();
        break;
    default:
        break;
    }
}
