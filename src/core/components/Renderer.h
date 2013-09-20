#ifndef RENDERER_H
#define RENDERER_H

#include <Artemis/Component.h>
#include "../Vector2D.h"

class Game;

namespace components {

class Renderer : public artemis::Component {
public:
    Renderer(float parallaxIndex = 1.0f);
    virtual ~Renderer() { }

    virtual void        render(Vector2D& position) = 0;

    inline float        getParallaxIndex() { return parallaxIndex; }

    inline void         setParallaxIndex(float pVal) { parallaxIndex = pVal; }

    inline Vector2D     getParallaxCompensation() { return parallaxCompensation; }

protected:
    float               parallaxIndex;
    Vector2D            parallaxCompensation;
};

}

#endif // RENDERER_H
