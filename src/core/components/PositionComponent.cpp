#include "PositionComponent.h"

PositionComponent::PositionComponent() {
    // Default Vector2D's constructor initalizes x and y = 0, so we don't need
    // to do it
}

PositionComponent::PositionComponent(float x, float y) {
    this->position.setX(x);
    this->position.setY(y);
}

PositionComponent::~PositionComponent() {
}



