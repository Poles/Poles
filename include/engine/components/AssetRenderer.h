#ifndef RENDERER_H
#define RENDERER_H

#include <Artemis/Component.h>
#include "engine/RenderizableAsset.h"
#include "engine/GameObject.h"

namespace components {

class AssetRenderer : public artemis::Component {
public:
    AssetRenderer();
    virtual ~AssetRenderer();

    void                                render(GameObject* camera, Vector2D position, float angle);

private:
    int                                 zIndex;
    int                                 distance;
    assets::RenderizableAsset*          asset;

};

}

#endif // RENDERER_H
