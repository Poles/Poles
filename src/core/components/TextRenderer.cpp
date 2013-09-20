#include "TextRenderer.h"
#include "../ResourceManager.h"
#include "../../game/Game.h"

using namespace components;

TextRenderer::TextRenderer():
    Renderer()
{
    this->pointSize = TEXT_DEFAULT_POINTSIZE;
    this->font = ResourceManager::getFont(TEXT_DEFAULT_FONT);
    this->foregroundColor = presetColors::COLOR_WHITE;
    this->backgroundColor = presetColors::COLOR_BLACK;
}

TextRenderer::TextRenderer(std::string text, const char * fontName, const float parallax):
    Renderer(parallax)
{
    this->pointSize = TEXT_DEFAULT_POINTSIZE;
    this->text = text;
    this->font = ResourceManager::getFont(fontName);
    this->foregroundColor = presetColors::COLOR_WHITE;
    this->backgroundColor = presetColors::COLOR_BLACK;
}

TextRenderer::~TextRenderer() {
    
}

/**
 * 
 * @param color
 */
void TextRenderer::setBackgroundColor(Color& color) {
    this->backgroundColor = color;
}

/**
 * 
 * @param color
 */
void TextRenderer::setForegroundColor(Color& color) {
    this->foregroundColor = color;
}

/**
 * 
 * @param fontName
 */
void TextRenderer::setFont(const char* fontName) {
    TTF_Font * font = ResourceManager::getFont(fontName);
    
    if (font != NULL) {
        this->font = font;
    }
}

/**
 * 
 * @param pointSize
 */
void TextRenderer::setPointSize(int pointSize) {
    if (pointSize < 0) {
        pointSize = 4;
    }
    
    this->pointSize = pointSize;
}

/**
 * 
 * @param position
 */
void TextRenderer::render(Vector2D & position) {
    SDL_Surface * textSurface;
    if (this->backgroundColor.alpha() == 0) {
        textSurface = TTF_RenderText_Blended(
                this->font,
                this->text.c_str(),
                this->foregroundColor.toSDLColor());
    } else {
        textSurface = TTF_RenderText(
            this->font,
            this->text.c_str(),
            this->foregroundColor.toSDLColor(),
            this->backgroundColor.toSDLColor());
    }
    
    if (textSurface == NULL) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
                                 "TextRenderer",
                                 SDL_GetError(),
                                 NULL);
    }

    SDL_Texture * textTexture = SDL_CreateTextureFromSurface(Game::currentRenderer(), textSurface);

    if (textTexture == NULL) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
                                 "TextRenderer",
                                 SDL_GetError(),
                                 NULL);
    }
    
    SDL_Rect * posRec = new SDL_Rect();
    
    posRec->x = position.x() - (textSurface->w / 2);
    posRec->y = position.y() - (textSurface->h / 2);
    posRec->w = textSurface->w;
    posRec->h = textSurface->h;
    
    SDL_RenderCopy(Game::currentRenderer(), textTexture, NULL, posRec);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
}

