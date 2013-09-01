#include "Sprite.h"
#include <iostream>
#include "../game/Game.h"

Sprite::Sprite(const char * imageFile, unsigned int rows, unsigned int columns) {
    this->currentAnimation = 0;
    this->currentFrame = 0;
    this->oscillate = false;
    
    this->image = IMG_LoadTexture(Game::currentRenderer(), imageFile);
    
    if (this->image != NULL) {
        // Get image's width and height
        SDL_QueryTexture(this->image, NULL, NULL, & this->width, & this->height);
        
        unsigned int pixelsPerRow;
        unsigned int pixelsPerColumn;
        
        pixelsPerRow = this->width / rows;
        pixelsPerColumn = this->height / columns;
        
        SDL_Rect * frame;
        for (int currentRow = 0; currentRow < rows; currentRow++) {
            // Insert a new row
            std::vector<SDL_Rect> row(columns);
            this->frames.push_back(row);
            for (int currentColumn = 0; currentColumn < columns; currentColumn++) {
                frame = new SDL_Rect;
                
                frame->x = currentColumn * pixelsPerColumn;
                frame->w = pixelsPerColumn;
                frame->y = currentRow * pixelsPerRow;
                frame->h = pixelsPerRow;
                
                this->frames[currentRow].push_back(* frame);
                
                delete frame;
            }
        }
        
    } else {
        std::cout << "Error! - Image " << imageFile << " couldn't be loaded" << std::endl;
        std::cout << IMG_GetError() << std::endl;
    }
}

Sprite::Sprite(const Sprite& orig) {
    
}

Sprite::~Sprite() {
    SDL_DestroyTexture(this->image);
}

/**
 * Area of the sprite corresponding to the current frame of the animation.
 * 
 * Use this area to render only the right part of the Sprite.
 * @return      Rectangle with the coordinates of the current frame to be displayed.
 */
SDL_Rect * Sprite::currentFrameBox() {
    return & (this->frames[this->currentAnimation][this->currentFrame]);
}

/**
 * 
 * @return 
 */
SDL_Texture * Sprite::texture() {
    return this->image;
}

/**
 * 
 * @return 
 */
int Sprite::getHeight() {
    return this->height;
}

/**
 * 
 * @return 
 */
int Sprite::getWidth() {
    return this->width;
}
