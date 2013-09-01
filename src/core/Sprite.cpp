#include "Sprite.h"
#include <iostream>

Sprite::Sprite(const char * imageFile, unsigned int rows, unsigned int columns) {
    this->image = IMG_Load(imageFile);
    
    if (this->image != NULL) {
        unsigned int pixelsPerRow;
        unsigned int pixelsPerColumn;
        
        pixelsPerRow = this->image->w / rows;
        pixelsPerColumn = this->image->h / columns;
        
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
    }
}

Sprite::Sprite(const Sprite& orig) {
}

Sprite::~Sprite() {
}

