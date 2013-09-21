#include "Renderer.h"
#include "../../game/Game.h"
#include "Camera.h"

using namespace components;

Renderer::Renderer(float parallaxIndex, Camera* cameraToRender) {
    this->parallaxIndex = parallaxIndex;

    Vector2D wantedDisplacement = Game::getMainCameraObject()->getPosition() - Game::getMainCamera()->getCorrectionVector();
    Vector2D obtainedDisplacement = (Game::getMainCameraObject()->getPosition() - Game::getMainCamera()->getCorrectionVector() * parallaxIndex);

    this->parallaxCompensation = obtainedDisplacement - wantedDisplacement;

    // By default we will use the main camera
    if (cameraToRender == NULL) {
        this->camera = Game::getMainCamera();
    } else {
        this->camera = cameraToRender;
    }

}

/**
 * @brief Renderer::addToRenderingQueue
 * @param position
 */
void Renderer::addToRenderingQueue(Vector2D &position) {
    this->camera->queueForRendering(this);
}

