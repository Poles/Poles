#include "TestScene.h"

#include "engine/Game.h"
#include <SDL2/SDL_image.h>
#include "engine/components/AssetRenderer.h"
#include "engine/components/Transform.h"
#include "engine/components/Camera.h"
#include "engine/SpriteSheet.h"

TestScene::TestScene() : Scene("Test Scene") {
    background = createGameObject("Background");

    background->addComponent(new components::AssetRenderer(new assets::SpriteSheet("Background", "assets/images/bg.png"), 0, 1000));
}

TestScene::~TestScene() {

}

void TestScene::onActivate() {

}

void TestScene::onDeactivate() {

}

void TestScene::onLoop() {
}

void TestScene::onRender() {
    components::Transform* transformComp = (components::Transform*)background->getComponent<components::Transform>();
    components::AssetRenderer* assetRendererComp = (components::AssetRenderer*)background->getComponent<components::AssetRenderer>();

    assetRendererComp->render(this->mainCamera, transformComp->getPosition(), transformComp->getScale(), transformComp->getRotation());

    ((components::Camera*)this->mainCamera->getComponent<components::Camera>())->renderScene();
}

void TestScene::onKeyDown(SDL_Keycode key, Uint16 mod) {
    Vector2D direction;
    switch (key) {
    case SDLK_LEFT:
        direction.setX(-100.0f);
        direction = direction * Game::deltaTime;
        ((components::Transform*)this->mainCamera->getComponent<components::Transform>())->move(direction);
        break;

    case SDLK_RIGHT:
        direction.setX(100.0f);
        direction = direction * Game::deltaTime;
        ((components::Transform*)this->mainCamera->getComponent<components::Transform>())->move(direction);
        break;

    case SDLK_UP:
        direction.setY(-100.0f);
        direction = direction * Game::deltaTime;
        ((components::Transform*)this->mainCamera->getComponent<components::Transform>())->move(direction);
        break;

    case SDLK_DOWN:
        direction.setY(100.0f);
        direction = direction * Game::deltaTime;
        ((components::Transform*)this->mainCamera->getComponent<components::Transform>())->move(direction);
        break;

    case SDLK_1:

        break;

    case SDLK_2:

        break;

    case SDLK_3:

        break;

    case SDLK_ESCAPE:
        Game::terminate();
        break;
    default:
        break;
    }
}
