#include "engine/components/Camera.h"
#include "engine/Game.h"

using namespace components;

/**
 * @brief Creates a new camera at the center point (0,0) rendering to the main window.
 */
Camera::Camera() :
    position(0,0) {
    // We use the default main window
    this->window = Game::window;
    this->index = 0;
}

/**
 * @brief Changes the current position of the camera.
 * @param x     X coordinate.
 * @param y     Y coordinate.
 */
void Camera::setPosition(int x, int y) {
    this->position.setX(x);
    this->position.setY(y);
}

/**
 * @brief Changes the index of the camera.
 *
 * Higher values will make the camera to be rendered later (if there are more than one camera
 * make sure you have set the index for each of them correctly).
 * @param index     Index to assign to the camera.
 */
void Camera::setIndex(int index) {
    this->index = index;
}

void Camera::queueForRender(Renderer *render, Vector2D position) {

}
