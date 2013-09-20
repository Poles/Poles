#include "Renderer.h"
#include "../../game/Game.h"

using namespace components;

Renderer::Renderer(float parallaxIndex) {
    this->parallaxIndex = parallaxIndex;

    Vector2D wantedDisplacement = Game::getMainCameraObject()->getPosition() - Game::getMainCamera()->getCorrectionVector();
    Vector2D obtainedDisplacement = (Game::getMainCameraObject()->getPosition() - Game::getMainCamera()->getCorrectionVector() * parallaxIndex);

    this->parallaxCompensation = obtainedDisplacement - wantedDisplacement;
}

