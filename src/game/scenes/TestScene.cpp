#include "TestScene.h"

#include "engine/Game.h"
#include <SDL2/SDL_image.h>

TestScene::TestScene() : Scene("Test Scene") {

}

void TestScene::onActivate() {
    createGameObject("Test01");

    this->cameraPos.setX(0);
    this->cameraPos.setY(0);

    this->objectPos.setX(0);
    this->objectPos.setY(0);

    bg = IMG_LoadTexture(Game::window->getRenderer(), "assets/images/bg.png");
}

void TestScene::onDeactivate() {
    destroyGameObject("Test01");
}

void TestScene::onLoop() {
}

void TestScene::onRender() {
    Vector2D objectPersPos;
    objectPersPos = Game::parallaxScrolling.applyParallaxScrolling(cameraPos, objectPos, 1000);

    Vector2D bgRenderingPos;
    bgRenderingPos = Game::parallaxScrolling.applyParallaxScrolling(cameraPos, bgPos, 0);

    std::cout << "Box = " << objectPersPos.toString() << " // BG = " << bgRenderingPos.toString() << std::endl;

    SDL_Rect objectRect;

    objectRect.x = objectPersPos.x();
    objectRect.y = objectPersPos.y();
    objectRect.w = 100;
    objectRect.h = 100;

    SDL_Rect bgRect;

    bgRect.x = bgRenderingPos.x();
    bgRect.y = bgRenderingPos.y();

    SDL_QueryTexture(this->bg, 0, 0, &bgRect.w, &bgRect.h);

    SDL_Renderer* renderer = Game::window->getRenderer();

    Uint8 r,g,b,a;
    SDL_GetRenderDrawColor(renderer, &r, &g, &b, &a);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    SDL_RenderCopy(renderer, this->bg, NULL, &bgRect);
    SDL_RenderDrawRect(renderer, &objectRect);

    SDL_SetRenderDrawColor(renderer, r, g, b, a);

}

void TestScene::onKeyDown(SDL_Keycode key, Uint16 mod) {
    Vector2D movement;

    switch (key) {

    case SDLK_LEFT:
        movement.setX(-100);
        movement = movement * Game::deltaTime;
        this->cameraPos = this->cameraPos + movement;
        break;

    case SDLK_RIGHT:
        movement.setX(100);
        movement = movement * Game::deltaTime;
        this->cameraPos = this->cameraPos + movement;
        break;

    case SDLK_UP:
        movement.setY(-100);
        movement = movement * Game::deltaTime;
        this->cameraPos = this->cameraPos + movement;
        break;

    case SDLK_DOWN:
        movement.setY(100);
        movement = movement * Game::deltaTime;
        this->cameraPos = this->cameraPos + movement;
        break;

    case SDLK_1:
        this->cameraPos.setX(0);
        this->cameraPos.setX(0);
        break;

    case SDLK_2:
        this->cameraPos.setX(-200);
        this->cameraPos.setY(-200);
        break;

    case SDLK_3:
        this->cameraPos.setX(123);
        this->cameraPos.setY(-123);
        break;

    case SDLK_ESCAPE:
        Game::terminate();
        break;
    default:
        break;
    }
}
