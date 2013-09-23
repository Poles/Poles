#ifndef PHYSICS_H
#define PHYSICS_H

#include <Artemis/Component.h>
#include "Vector2D.h"

namespace components {

class Physics : public artemis::Component {
public:
    Physics(float weight = 1.0f, float drag = 0.0f, bool usesGravity = true, bool kinematic = false);

private:
    float               weight;     // Weight of the object. This will affect the force needed by other objects to move this one.
    float               drag;       // Resistance to gravity. A feather will have a lot of drag. A rock will have none.

    bool                usesGravity;// If uses gravity, this object will be affected by gravity each frame.
    bool                kinematic;  // If kinematic, other objects can't move it, only gravity will move him.
};

}

#endif // PHYSICS_H
