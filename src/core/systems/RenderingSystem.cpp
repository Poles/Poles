#include "RenderingSystem.h"
#include "../../game/Game.h"

#include <sstream>

RenderingSystem::RenderingSystem() {
    
    addComponentType<components::Position>();
    addComponentType<components::SpriteRenderer>();
}

void RenderingSystem::initialize() {
    this->positionMapper.init(* world);
    this->spriteMapper.init(* world);
}

RenderingSystem::~RenderingSystem() {
    
}

void RenderingSystem::processEntity(artemis::Entity& e) {
    Vector2D position = positionMapper.get(e)->getPosition();
    Vector2D cameraCorrection = (Game::getMainCameraObject()->getPosition() - Game::getMainCamera()->getCorrectionVector()) * spriteMapper.get(e)->getParallaxIndex();
    position = position - cameraCorrection;
    spriteMapper.get(e)->render(position);
}
