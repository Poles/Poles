#include "Sprite.h"
#include <iostream>
#include "../game/Game.h"

/**
 * 
 * @param imageFile
 * @param animations
 * @param framesPerAnimation
 */
Sprite::Sprite(const char * imageFile, unsigned int animations, unsigned int * framesPerAnimation) {
    this->currentAnimation = 0;
    this->currentFrame = 0;
    this->oscillate = false;
    this->frameIncrement = 1;
    this->frameRate = 1000;
    this->oldTime = SDL_GetTicks();
    
    this->image = IMG_LoadTexture(Game::currentRenderer(), imageFile);
    
    if (this->image != NULL) {
        // Get image's width and height
        int width;
        int height;
        
        SDL_QueryTexture(this->image, NULL, NULL, & width, & height);
        
        this->width = width;
        this->height = height;
        
        unsigned int heightPerRow;
        unsigned int widthPerColumn;
        
        heightPerRow = this->height / animations;
        
        // We search the longest animation which will determine the number of pixels per column
        unsigned int maxNumberOfFrames = 1;
        for (int animation = 0; animation < animations; animation++) {
            if (framesPerAnimation[animation] > maxNumberOfFrames) {
                maxNumberOfFrames = framesPerAnimation[animation];
            }
        }
        widthPerColumn = this->width / maxNumberOfFrames;
        
        this->widthPerFrame = widthPerColumn;
        this->heightPerFrame = heightPerRow;
        
        SDL_Rect * frameBox = NULL;
        for (int animation = 0; animation < animations; animation++) {
            // Insert a new row of animations
            unsigned int numberOfFrames = framesPerAnimation[animation];
            std::vector<SDL_Rect> row(numberOfFrames);
            this->frames.push_back(row);
            
            for (int frame = 0; frame < numberOfFrames; frame++) {
                frameBox = new SDL_Rect;
                
                frameBox->x = frame * widthPerColumn;
                frameBox->y = animation * heightPerRow;
                frameBox->w = widthPerColumn;
                frameBox->h = heightPerRow;
                
                this->frames[animation][frame] = * frameBox;
                
                delete frameBox;
            }
        }
        
    } else {
        std::cout << "Error! - Image " << imageFile << " couldn't be loaded" << std::endl;
        std::cout << IMG_GetError() << std::endl;
    }
    std::cout << std::endl;
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
SDL_Rect * Sprite::getCurrentFrameBox() {
    return & (this->frames[this->currentAnimation][this->currentFrame]);
}

/**
 * 
 * @return 
 */
SDL_Texture * Sprite::getTexture() {
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

/**
 * Prints the values of the sprite frames.
 * 
 * This is used for debug operations.
 */
void Sprite::showAnimationFramesInfo() {
    std::cout << "Number of animations: " << this->frames.size() << std::endl;
    for (int row = 0; row < this->frames.size(); row++) {
        std::cout << "Animation " << row << " (" << this->frames[row].size() << ")    ";
        for (int column = 0; column < this->frames[row].size(); column++) {
            std::cout << "[" << this->frames[row][column].x << "," << this->frames[row][column].y
                    << " + " << this->frames[row][column].w << "," << this->frames[row][column].h << "] ";
        }
        std::cout << std::endl;
    }
}

/**
 * 
 * @param position
 */
void Sprite::render(Vector2D& position) {
    SDL_Rect * pos = new SDL_Rect;
    
    pos->x = position.x();
    pos->y = position.y();
    pos->w = this->widthPerFrame;
    pos->h = this->heightPerFrame;
    
    SDL_RenderCopy(
            Game::currentRenderer(),
            this->image,
            this->getCurrentFrameBox(),
            pos);
    
    updateAnimation();
}

/**
 * Binds an animation's index with a given name.
 * 
 * This way it is easier to refer to animations in the future.
 * @param name          Name given to the animation.
 * @param animation     Index of the animation to bind (position for the row in the matrix of animations).
 * @return              true if the binding was correct, false otherwise.
 */
bool Sprite::bindAnimation(const char * name, unsigned int animation) {
    if (animation > this->frames.size()) {
        std::cout << "Error! - Sprite: Binding animation with index out of range." << std::endl;
        return false;
    }
    
    if (this->animationsBindingMap.count(name) > 0) {
        std::cout << "Error! - Sprite: Binding animation with name already used." << std::endl;
        return false;
    }
    
    std::pair<const char *, unsigned int> binding(name, animation);
    this->animationsBindingMap.insert(binding);
    
    return true;
}

/**
 * Unbind an animation so its index is no longer binded to the given name.
 * @param name  Name with which the animation is currently binded.
 */
void Sprite::unbindAnimation(const char* name) {
    std::map<const char *, unsigned int>::iterator animation;
    
    animation = this->animationsBindingMap.find(name);
    
    if (animation != this->animationsBindingMap.end()) {
        this->animationsBindingMap.erase(animation);
    }
}

/**
 * Changes the current displayed animation of the sprite.
 * @param name  Name of the binded animation to display.
 */
void Sprite::setAnimation(const char* name) {
    std::map<const char *, unsigned int>::iterator animation;
    
    animation = this->animationsBindingMap.find(name);
    
    if (animation != this->animationsBindingMap.end()) {
        this->currentAnimation = animation->second;
    } else {
        std::cout << "Error! - Sprite: Trying to change to animation " << name << " but it is not binded." << std::endl;
    }
}

void Sprite::updateAnimation() {
    if (this->oldTime + this->frameRate > SDL_GetTicks()) {
        return; // ???
    }
    
    this->oldTime = SDL_GetTicks();
    
    this->currentFrame += this->frameIncrement;
    
    if (this->oscillate) {
        // If we are advancing in the animation
        if (this->frameIncrement > 0) {
            if (this->currentFrame >= this->frames[this->currentAnimation].size()) {
                // We reverse the direction of the animation
                this->frameIncrement = (-1) * this->frameIncrement;
            }
        }else {
            if (currentFrame < 0) {
                this->frameIncrement = (-1) * this->frameIncrement;
            }
        }
    } else {
        if (this->currentFrame >= this->frames[this->currentAnimation].size()) {
            this->currentFrame = 0;
        }
    }
}
