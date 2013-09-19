#include "MovementSystem.h"
#include <SDL2/SDL.h>
#include <sstream>

MovementSystem::MovementSystem() {
    addComponentType<components::Position>();
    addComponentType<components::Velocity>();
}

void MovementSystem::initialize() {
    velocityMapper.init(* world);
    positionMapper.init(* world);
}

MovementSystem::~MovementSystem() {
}

void MovementSystem::processEntity(artemis::Entity & e) {
    Vector2D velocity = velocityMapper.get(e)->velocityVector();
    positionMapper.get(e)->move(velocity);
}
