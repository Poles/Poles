#ifndef PARALLAXLAYERS_H
#define PARALLAXLAYERS_H

#include "engine/Vector2D.h"

namespace systems {

class ParallaxScrolling {
public:
    ParallaxScrolling();
    virtual ~ParallaxScrolling();

    void                                setBackgroundDistance(int distance);
    int                                 getBackgroundDistance();

    Vector2D                            applyParallaxScrolling(Vector2D cameraPosition, Vector2D objectPosition, int objectDistanceFromCamera);

private:
    int                                 backgroundDistance; // Distance of the static background

};

}

#endif // PARALLAXLAYERS_H
