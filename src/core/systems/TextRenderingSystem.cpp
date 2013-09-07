#include "TextRenderingSystem.h"

TextRenderingSystem::TextRenderingSystem() {
    addComponentType<PositionComponent>();
    addComponentType<TextRendererComponent>();
}

void TextRenderingSystem::initialize() {
    this->positionMapper.init(* world);
    this->rendererMapper.init(* world);
}

TextRenderingSystem::~TextRenderingSystem() {
    
}

void TextRenderingSystem::processEntity(artemis::Entity& e) {
    Vector2D position = positionMapper.get(e)->getPosition();    
    rendererMapper.get(e)->render(position);
}
