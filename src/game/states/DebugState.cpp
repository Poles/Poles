#include "DebugState.h"
#include <sstream>
#include "../Game.h"
#include "../../core/ResourceManager.h"
#include "../../core/Color.h"
#include "../GameStateManager.h"
#include "../core/components/Collisions.h"

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

    A = Game::createGameObject();
    B = Game::createGameObject();

    A->setPosition(30, 24);

    components::SpriteRenderer* sprite = (components::SpriteRenderer*)A->addComponent(new components::SpriteRenderer("spriteSheet_template", 10, 1.0f));
    A->addComponent(new components::Velocity());
    A->addComponent(new components::Collisions(0, 0, sprite));

    sprite = (components::SpriteRenderer*)B->addComponent(new components::SpriteRenderer("zero", 10, 1.0f));
    B->addComponent(new components::Velocity());
    B->addComponent(new components::Collisions(0, 0, sprite));

    // Register for collisions
    Game::collisionSystem.registerObject(A);
    Game::collisionSystem.registerObject(B);
}

void DebugState::onDeactivate() {

}

void DebugState::onLoop() {
    std::vector<GameObject* > collisions = Game::collisionSystem.checkCollisions(B);

    std::cout << "Zero collides with " << collisions.size() << " objects." << std::endl;
}

void DebugState::onRender() {

}

void DebugState::onKeyDown(SDL_Keycode key, Uint16 mod) {
    Vector2D force;
    switch (key) {
    case SDLK_LEFT:
        if (!keyDown) {
            B->addForce(-1.0f, 0.0f);
            B->changeAnimation("Walk Left");
            this->keyDown = true;
        }
        break;
            
    case SDLK_RIGHT:
        if (!keyDown) {
            B->addForce(1.0f, 0.0f);
            B->changeAnimation("Walk Right");
            this->keyDown = true;
        }
        break;

    case SDLK_UP:
        if (!keyDown) {


            this->keyDown = true;
        }
        break;

    case SDLK_DOWN:
        if (!keyDown) {


            this->keyDown = true;
        }
        break;

    case SDLK_1:

        break;
            
    case SDLK_ESCAPE:
        Game::exit();
        break;
    }
    
}

void DebugState::onKeyUp(SDL_Keycode key, Uint16 mod) {    
    switch (key) {
    case SDLK_LEFT:
        B->resetForce();
        B->changeAnimation("Stand Left");
        break;
    case SDLK_RIGHT:
        B->resetForce();
        B->changeAnimation("Stand Right");
        break;
    case SDLK_UP:

        break;
    case SDLK_DOWN:

        break;
    }
    this->keyDown = false;
    
}

