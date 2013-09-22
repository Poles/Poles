#ifndef RENDERER_H
#define RENDERER_H

#include <Artemis/Component.h>
#include "../Vector2D.h"

class Game;

namespace components {

class Camera;

class Renderer : public artemis::Component {
public:
    Renderer(int zIndex = 0, float parallaxIndex = 1.0f, Camera* cameraToRender = NULL);
    virtual ~Renderer() { }

    virtual void        render(Vector2D& position) = 0;

    inline int          getZIndex() { return zIndex; }

    inline void         setZIndex(int zVal) { this->zIndex = zVal; }

    inline float        getParallaxIndex() { return parallaxIndex; }

    inline void         setParallaxIndex(float pVal) { parallaxIndex = pVal; }

    inline Vector2D     getParallaxCompensation() { return parallaxCompensation; }

    inline Camera*      getCameraToRender() { return camera; }

    inline void         setCameraToRender(Camera* camera) { this->camera = camera; }

    void                addToRenderingQueue(Vector2D & position);

    inline Vector2D&    getRenderingPosition() { return renderingPosition; }

protected:
    int                 zIndex;
    float               parallaxIndex;
    Vector2D            parallaxCompensation;

    Vector2D            renderingPosition;

    Camera*             camera; // The camera the component will use to render its content
};

}

#endif // RENDERER_H
