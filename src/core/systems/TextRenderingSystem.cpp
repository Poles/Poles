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
    Vector2D position;
    Vector2D cameraCorrection;
    Vector2D cameraPosition;
    Vector2D parallaxCorrection;
    float parallaxIndex;

    position = positionMapper.get(e)->getPosition();
    cameraPosition = (Game::getMainCameraObject()->getPosition());
    cameraCorrection = (Game::getMainCamera()->getCorrectionVector());
    parallaxCorrection = rendererMapper.get(e)->getParallaxCompensation();
    parallaxIndex = rendererMapper.get(e)->getParallaxIndex();

    // Apply parallax effect
    position = position - ((cameraPosition - cameraCorrection) * parallaxIndex) + parallaxCorrection;
    rendererMapper.get(e)->render(position);
}
