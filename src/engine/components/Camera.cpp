#include "engine/components/Camera.h"
#include "engine/Game.h"

using namespace components;

/**
 * @brief Creates a new camera at the center point (0,0) rendering to the main window.
 * @param transform     Transform component of the GameObjec that contains the camara.
 */
Camera::Camera(components::Transform *transform) {
    // We use the default main window
    this->window = Game::window;
    this->index = 0;
    this->transform = transform;
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

/**
 * @brief Adds the given queue to the rendeing queue.
 *
 * Its position in the queue will depend on its zIndex.
 * The position on the screen will be affected by parallax effect relative to this camera.
 * @param package   Render Package to insert in the queue.
 */
void Camera::queueForRender(RenderPackage package) {
    // Apply parallax transformation
    package.position = Game::parallaxScrolling.applyParallaxScrolling(this->transform->getPosition(), package.position, package.distance);

    // Insert into the queue
    if (this->renderingQueue.size() == 0) {
        this->renderingQueue.push_back(package);
    } else {
        std::list<RenderPackage>::iterator it;

        it = this->renderingQueue.begin();
        bool found = false;
        while (found == false && it != this->renderingQueue.end()) {
            if ((*it).zIndex < package.zIndex) {
                ++it;
            } else {
                found = true;
            }
        }
        this->renderingQueue.insert(it, package);
    }
}

/**
 * @brief Renders the scene into the window.
 *
 * The content will be shown when Window call its draw() method.
 */
void Camera::renderScene() {
    std::list<RenderPackage>::iterator it;

    for (it = this->renderingQueue.begin(); it != this->renderingQueue.end(); ++it) {
        (*it).asset->render(this->window->getRenderer(),
                            (*it).position,
                            (*it).scale,
                            (*it).rotation);
    }

    this->renderingQueue.clear();
}
