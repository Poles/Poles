#include "DebugState.h"
#include <sstream>
#include "../Game.h"
#include "../../core/ResourceManager.h"
#include "../../core/Color.h"
#include "../GameStateManager.h"

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
    this->collisionBoxColor = presetColors::COLOR_GREEN;

    background = Game::createGameObject();
    terrain = Game::createGameObject();
    zero = Game::createGameObject();
    poles_dude = Game::createGameObject();

    zero->addComponent(new components::Velocity());

    //Game::getMainCameraObject()->setParent(zero);

    background->addComponent(new components::SpriteRenderer("BG-Sky-Blue-Stars.png", 0 ,0.0f));
    terrain->addComponent(new components::SpriteRenderer("terrain.png", 1, 1.0f));
    components::SpriteRenderer* sprite = (components::SpriteRenderer*)zero->addComponent(new components::SpriteRenderer("zero", 2, 1.0f));
    zeroBox = new CollisionBox(0, 0, sprite->getFrameWidth(), sprite->getFrameHeight());

    sprite = (components::SpriteRenderer*)poles_dude->addComponent(new components::SpriteRenderer("poles_dude", 2,0.5f));
    poles_dudeBox = new CollisionBox(0, 0, sprite->getFrameWidth(), sprite->getFrameHeight());

    poles_dude->setPosition(35, 0);
    terrain->setPosition(0, 38);

}

void DebugState::onDeactivate() {
    Game::destroyGameObject(zero);
    Game::destroyGameObject(terrain);
    Game::destroyGameObject(background);
    Game::destroyGameObject(poles_dude);
}

void DebugState::onLoop() {
    // If you need to update something each frame
    if (zeroBox->collides(zero->getPositionPerspective(), *poles_dudeBox, poles_dude->getPositionPerspective())) {
        this->collisionBoxColor = presetColors::COLOR_RED;
    } else {
        this->collisionBoxColor = presetColors::COLOR_GREEN;
    }

}

void DebugState::onRender() {
    // If you need to render something in addition to normal rendering
    zeroBox->render(Game::getMainCamera(), zero->getPositionPerspective(), this->collisionBoxColor);
    poles_dudeBox->render(Game::getMainCamera(), poles_dude->getPositionPerspective(), this->collisionBoxColor);
}

void DebugState::onKeyDown(SDL_Keycode key, Uint16 mod) {
    Vector2D force;
    switch (key) {
    case SDLK_LEFT:
        if (!keyDown) {
            //Game::getMainCameraObject()->addForce(-1.0f, 0.0f);
            zero->addForce(-3.0f, 0.0f);
            zero->changeAnimation("Walk Left");
            this->keyDown = true;
        }
        break;
            
    case SDLK_RIGHT:
        if (!keyDown) {
            //Game::getMainCameraObject()->addForce(1.0f, 0.0f);
            zero->addForce(3.0f, 0.0f);
            zero->changeAnimation("Walk Right");
            this->keyDown = true;
        }
        break;

    case SDLK_UP:
        if (!keyDown) {
            //Game::getMainCameraObject()->addForce(0.0f, -1.0f);

            this->keyDown = true;
        }
        break;

    case SDLK_DOWN:
        if (!keyDown) {
            //Game::getMainCameraObject()->addForce(0.0f, 1.0f);

            this->keyDown = true;
        }
        break;

    case SDLK_1:
        GameStateManager::setGameState(GAMESTATE_PARALLAX_TEST);
        break;
            
    case SDLK_ESCAPE:
        Game::exit();
        break;
    }
    
}

void DebugState::onKeyUp(SDL_Keycode key, Uint16 mod) {    
    switch (key) {
    case SDLK_LEFT:
        zero->changeAnimation("Stand Left");
        zero->resetForce();
        break;
    case SDLK_RIGHT:
        zero->changeAnimation("Stand Right");
        zero->resetForce();
        break;
    case SDLK_UP:

        break;
    case SDLK_DOWN:
        //Game::getMainCameraObject()->resetForce();
        zero->resetForce();
        break;
    }
    this->keyDown = false;
    
}

