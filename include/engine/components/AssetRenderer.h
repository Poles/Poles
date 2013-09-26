#ifndef RENDERER_H
#define RENDERER_H

#include <Artemis/Component.h>
#include "engine/RenderizableAsset.h"
#include "engine/GameObject.h"

namespace components {

/**
 * @brief Component used to render any asset capable of being rendered into the scene
 */
class AssetRenderer : public artemis::Component {
public:
    AssetRenderer();
    AssetRenderer(assets::RenderizableAsset* asset, int zIndex = 0, int distance = 0);
    virtual ~AssetRenderer();

    void                                render(GameObject* camera, Vector2D position, Vector2D scale, float rotation);

    inline void                         setVisible(bool visible) { this->visible = visible; }
    inline bool                         isVisible() { return this->visible; }

private:
    int                                 zIndex;
    int                                 distance;
    assets::RenderizableAsset*          asset;
    bool                                visible;

};

}

#endif // RENDERER_H
