#include "RenderingSystem.h"
#include "../../game/Game.h"

#include <sstream>

RenderingSystem::RenderingSystem() {
    
    addComponentType<PositionComponent>();
    addComponentType<SpriteSheetRendererComponent>();
}

void RenderingSystem::initialize() {
    this->positionMapper.init(* world);
    this->spriteMapper.init(* world);
}

RenderingSystem::~RenderingSystem() {
    
}

void RenderingSystem::processEntity(artemis::Entity& e) {
    Vector2D position = positionMapper.get(e)->getPosition();
    position = position - (Game::getMainCameraObject()->getPosition() - Game::getMainCamera()->getCorrectionVector());    
    spriteMapper.get(e)->render(position);
}
