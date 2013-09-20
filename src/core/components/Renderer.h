#ifndef RENDERER_H
#define RENDERER_H

#include <Artemis/Component.h>
#include "../Vector2D.h"

namespace components {

class Renderer : public artemis::Component {
public:
    Renderer() { parallaxIndex = 1.0f; }
    virtual ~Renderer() { }

    virtual void render(Vector2D& position) = 0;

    inline float getParallaxIndex() { return parallaxIndex; }

    inline void setParallaxIndex(float pVal) { parallaxIndex = pVal; }

protected:
    float parallaxIndex;
};

}

#endif // RENDERER_H
