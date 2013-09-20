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
    Vector2D position;
    Vector2D cameraCorrection;
    Vector2D cameraPosition;
    Vector2D parallaxCorrection;
    float parallaxIndex;

    position = positionMapper.get(e)->getPosition();
    cameraPosition = (Game::getMainCameraObject()->getPosition());
    cameraCorrection = (Game::getMainCamera()->getCorrectionVector());
    parallaxCorrection = spriteMapper.get(e)->getParallaxCompensation();
    parallaxIndex = spriteMapper.get(e)->getParallaxIndex();

    // Apply parallax effect
    position = position - ((cameraPosition - cameraCorrection) * parallaxIndex) + parallaxCorrection;
    spriteMapper.get(e)->render(position);
}
