#include "TextRendererComponent.h"
#include "../ResourceManager.h"
#include "../../game/Game.h"

TextRendererComponent::TextRendererComponent() {
    this->pointSize = TEXT_DEFAULT_POINTSIZE;
    this->font = ResourceManager::getFont(TEXT_DEFAULT_FONT);
    this->foregroundColor = presetColors::COLOR_BLACK;
    this->backgroundColor = presetColors::COLOR_WHITE;
    this->backgroundColor.setAlpha(0);  // Transparent
}

TextRendererComponent::TextRendererComponent(std::string text, const char * fontName) {
    this->pointSize = TEXT_DEFAULT_POINTSIZE;
    this->text = text;
    this->font = ResourceManager::getFont(fontName);
    this->foregroundColor = presetColors::COLOR_BLACK;
    this->backgroundColor = presetColors::COLOR_WHITE;
    this->backgroundColor.setAlpha(0);  // Transparent
}

TextRendererComponent::~TextRendererComponent() {
    
}

/**
 * 
 * @param color
 */
void TextRendererComponent::setBackgroundColor(Color& color) {
    this->backgroundColor = color;
}

/**
 * 
 * @param color
 */
void TextRendererComponent::setForegroundColor(Color& color) {
    this->foregroundColor = color;
}

/**
 * 
 * @param fontName
 */
void TextRendererComponent::setFont(const char* fontName) {
    TTF_Font * font = ResourceManager::getFont(fontName);
    
    if (font != NULL) {
        this->font = font;
    }
}

/**
 * 
 * @param pointSize
 */
void TextRendererComponent::setPointSize(int pointSize) {
    if (pointSize < 0) {
        pointSize = 4;
    }
    
    this->pointSize = pointSize;
}

/**
 * 
 * @param position
 */
void TextRendererComponent::render(Vector2D & position) {
    SDL_Surface * textSurface = TTF_RenderText(
            this->font,
            this->text.c_str(),
            this->foregroundColor.toSDLColor(),
            this->backgroundColor.toSDLColor());
    
    SDL_Texture * textTexture = SDL_CreateTextureFromSurface(Game::currentRenderer(), textSurface);
    
    SDL_Rect * posRec = new SDL_Rect();
    
    posRec->x = position.x() - (textSurface->w / 2);
    posRec->y = position.y() - (textSurface->h / 2);
    posRec->w = textSurface->w;
    posRec->h = textSurface->h;
    
    SDL_RenderCopy(Game::currentRenderer(), textTexture, NULL, posRec);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
}

