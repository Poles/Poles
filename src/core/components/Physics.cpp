#include "Physics.h"

using namespace components;

Physics::Physics(float weight, float drag, bool usesGravity, bool kinematic) {
    this->weight = weight;
    this->drag = drag;
    this->usesGravity = usesGravity;
    this->kinematic = kinematic;
}
