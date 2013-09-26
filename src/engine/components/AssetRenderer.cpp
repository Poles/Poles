#include "engine/components/AssetRenderer.h"
#include "engine/components/Camera.h"
#include "engine/Game.h"
#include <sstream>

using namespace components;

/**
 * @brief AssetRenderer::AssetRenderer
 */
AssetRenderer::AssetRenderer() {
    this->zIndex = 0;
    this->distance = 0;
    this->asset = NULL;
    this->visible = true;
}

/**
 * @brief AssetRenderer::AssetRenderer
 * @param asset
 * @param zIndex
 * @param distance
 */
AssetRenderer::AssetRenderer(assets::RenderizableAsset *asset, int zIndex, int distance) {
    this->zIndex = zIndex;
    this->distance = distance;
    this->asset = asset;
    this->visible = true;
}

AssetRenderer::~AssetRenderer() {

}

/**
 * @brief Draws the asset into the camera at the given position.
 * @param camera        GameObject with a components::Camera attached.
 * @param position      Screen position where the asset will be rendered (center point, not the upper left corner).
 * @param angle         Rotation angle from the center point
 */
void AssetRenderer::render(GameObject* camera, Vector2D position, Vector2D scale, float rotation) {
    components::Camera* cameraComponent;

    cameraComponent = (components::Camera*)camera->getComponent<components::Camera>();

    if (cameraComponent != NULL && this->asset != NULL && this->visible == true) {
        RenderPackage package;

        package.asset = this->asset;
        package.position = position;
        package.scale = scale;
        package.rotation = rotation;
        package.distance = this->distance;
        package.zIndex = this->zIndex;

        // Add to the camera rendering queue
        cameraComponent->queueForRender(package);
    } else {
        std::stringstream text;

        text << "Error - Trying to render to " << camera->getName() << " object with no camera component attached.";
        Game::writeToConsole(text.str());
    }
}
