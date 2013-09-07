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
}

Sprite::Sprite(const Sprite& orig) {
    
}

Sprite::~Sprite() {
    SDL_DestroyTexture(this->image);
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

int Sprite::getAnimationIndex(const char* name) {
    std::map<const char *, unsigned int>::iterator animationBind = this->animationsBindingMap.find(name);
    
    if (animationBind != this->animationsBindingMap.end()) {
        return animationBind->second;
    } else {
        return -1;
    }
}

/**
 * 
 * @param animation
 * @param frame
 * @return 
 */
SDL_Rect * Sprite::getFrameBox(const char * animation, unsigned int frame) {
    if (animation != NULL) {
        std::map<const char *, unsigned int>::iterator animationBind = this->animationsBindingMap.find(animation);

        unsigned int animationIndex = 0;
        if (animationBind != this->animationsBindingMap.end()) {
            animationIndex = animationBind->second;
            if (frame < this->frames[animationIndex].size()) {
                    return & (this->frames[animationIndex][frame]);
            }
        }
    } else {
        std::cout << "Error! - Sprite: You have passed a NULL name as animation name." << std::endl;
    }
    
    return NULL;
}

int Sprite::getNumberOfFrames(const char * animation) {
    std::map<const char *, unsigned int>::iterator animationBind = this->animationsBindingMap.find(animation);
    
    if (animationBind != this->animationsBindingMap.end()) {
        unsigned int animationIndex = animationBind->second;
        
        return this->frames[animationIndex].size();
    }
    
    return -1;
}

const char * Sprite::getAnimationName(const unsigned int animationIndex) {
    std::map<const char *, unsigned int>::iterator animation;
    
    for (animation = this->animationsBindingMap.begin(); animation != this->animationsBindingMap.end(); animation++) {
        if (animation->second == animationIndex) {
            return animation->first;
        }
    }
    
    return NULL;
}
