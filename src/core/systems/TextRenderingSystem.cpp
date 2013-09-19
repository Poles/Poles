#include "TextRenderingSystem.h"
#include "../../game/Game.h"

TextRenderingSystem::TextRenderingSystem() {
    addComponentType<components::Position>();
    addComponentType<components::TextRenderer>();
}

void TextRenderingSystem::initialize() {
    this->positionMapper.init(* world);
    this->rendererMapper.init(* world);
}

TextRenderingSystem::~TextRenderingSystem() {
    
}

void TextRenderingSystem::processEntity(artemis::Entity& e) {
    Vector2D position = positionMapper.get(e)->getPosition(); 
    position = position - (Game::getMainCameraObject()->getPosition() - Game::getMainCamera()->getCorrectionVector());   
    rendererMapper.get(e)->render(position);
}
