#ifndef CAMERA_H
#define CAMERA_H

#include <Artemis/Component.h>
#include <SDL2/SDL.h>
#include "engine/Vector2D.h"
#include "engine/Window.h"
#include <list>

#include "engine/components/AssetRenderer.h"
#include "engine/components/Transform.h"

// ==================================================== //
typedef struct {
    assets::RenderizableAsset*          asset;
    Vector2D                            position;
    Vector2D                            scale;
    float                               rotation;
    int                                 zIndex;
    int                                 distance;
}RenderPackage;
// ==================================================== //

namespace components {

class Camera : public artemis::Component {
public:
    Camera(components::Transform* transform);

    void                                setIndex(int index);
    inline int                          getIndex() { return index; }

    void                                queueForRender(RenderPackage package);
    void                                renderScene();

private:
    Window*                             window;     // Window where the rendering will be done
    int                                 index;      // Used to render the cameras in a given order

    std::list<RenderPackage>            renderingQueue; // Contains the components to be renderized in rendering order
    Transform*                          transform;      // Transform of the object that contains the camera
};

}

#endif // CAMERA_H
