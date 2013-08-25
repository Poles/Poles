#include "MovementSystem.h"

MovementSystem::MovementSystem() {
    addComponentType<PositionComponent>();
    addComponentType<VelocityComponent>();
}

void MovementSystem::initialize() {
    velocityMapper.init(* world);
    positionMapper.init(* world);
}

MovementSystem::~MovementSystem() {
}

void MovementSystem::processEntity(artemis::Entity& e) {
    Vector2D velocity = velocityMapper.get(e)->velocityVector();
    positionMapper.get(e)->move(velocity);
}
