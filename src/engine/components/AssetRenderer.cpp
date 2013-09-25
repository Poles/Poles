#include "engine/components/AssetRenderer.h"

using namespace components;

AssetRenderer::AssetRenderer() {

}

AssetRenderer::~AssetRenderer() {

}

/**
 * @brief Draws the asset into the camera at the given position.
 * @param camera        GameObject with a components::Camera attached.
 * @param position      Screen position where the asset will be rendered (center point, not the upper left corner).
 * @param angle         Rotation angle from the center point
 */
void AssetRenderer::render(GameObject* camera, Vector2D position, float angle) {

}
