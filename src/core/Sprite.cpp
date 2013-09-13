#include "Sprite.h"
#include <iostream>
#include <sstream>
#include "../game/Game.h"

/**
 * 
 * @param imageFile
 * @param animations
 * @param framesPerAnimation
 */
Sprite::Sprite(const char * imageFile, unsigned int animations, unsigned int * framesPerAnimation) {
    this->image = NULL;
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
        if (framesPerAnimation != NULL) {
            for (unsigned int animation = 0; animation < animations; ++animation) {
                if (framesPerAnimation[animation] > maxNumberOfFrames) {
                    maxNumberOfFrames = framesPerAnimation[animation];
                }
            }
        }
        widthPerColumn = this->width / maxNumberOfFrames;
        
        this->widthPerFrame = widthPerColumn;
        this->heightPerFrame = heightPerRow;
        
        SDL_Rect * frameBox = NULL;
        for (unsigned int animation = 0; animation < animations; ++animation) {
            // Insert a new row of animations
            unsigned int numberOfFrames = framesPerAnimation[animation];
            std::vector<SDL_Rect> row(numberOfFrames);
            this->frames.push_back(row);
            
            for (unsigned int frame = 0; frame < numberOfFrames; frame++) {
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

Sprite::~Sprite() {
    SDL_DestroyTexture(this->image);
}

/**
 * Prints the values of the sprite frames.
 * 
 * This is used for debug operations.
 */
void Sprite::showAnimationFramesInfo() {
    std::stringstream stream;
    stream << "Number of animations: " << this->frames.size() << std::endl;
    for (unsigned int row = 0; row < this->frames.size(); row++) {
        stream << "Animation " << row << " (" << this->frames[row].size() << ")    ";
        for (unsigned int column = 0; column < this->frames[row].size(); column++) {
            stream << "[" << this->frames[row][column].x << "," << this->frames[row][column].y
                    << " + " << this->frames[row][column].w << "," << this->frames[row][column].h << "] ";
        }
        stream << std::endl;
    }
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
            "Sprite",
            stream.str().c_str(),
            NULL);
}

void Sprite::showAnimationBindings() {
    std::stringstream stream;
    
    for (std::map<std::string, unsigned int>::iterator binding = this->animationsBindingMap.begin();
            binding != this->animationsBindingMap.end();
            ++binding) {
        stream << binding->first << ": " << binding->second << std::endl;
    }
    
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
            "Sprite",
            stream.str().c_str(),
            NULL);    
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
    if (animation >= this->frames.size()) {
        std::cout << "Error! - Sprite: Binding animation with index out of range." << std::endl;
        return false;
    }
    
    if (this->animationsBindingMap.count(name) > 0) {
        std::cout << "Error! - Sprite: Binding animation with name already used." << std::endl;
        return false;
    }
    
    std::pair<std::string, unsigned int> binding(std::string(name), animation);
    this->animationsBindingMap.insert(binding);
    
    return true;
}

/**
 * Unbind an animation so its index is no longer binded to the given name.
 * @param name  Name with which the animation is currently binded.
 */
void Sprite::unbindAnimation(const char * name) {
    std::map<std::string, unsigned int>::iterator animation;
    
    animation = this->animationsBindingMap.find(name);
    
    if (animation != this->animationsBindingMap.end()) {
        this->animationsBindingMap.erase(animation);
    }
}

int Sprite::getAnimationIndex(const char * name) {
    std::map<std::string, unsigned int>::iterator animationBind = this->animationsBindingMap.find(std::string(name));
    
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
        std::map<std::string, unsigned int>::iterator animationBind = this->animationsBindingMap.find(std::string(animation));

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
    std::map<std::string, unsigned int>::iterator animationBind = this->animationsBindingMap.find(std::string(animation));
    
    if (animationBind != this->animationsBindingMap.end()) {
        unsigned int animationIndex = animationBind->second;
        
        return this->frames[animationIndex].size();
    }
    
    return -1;
}

const char * Sprite::getAnimationName(const unsigned int animationIndex) {
    std::map<std::string, unsigned int>::iterator animation;
    
    for (animation = this->animationsBindingMap.begin(); animation != this->animationsBindingMap.end(); animation++) {
        if (animation->second == animationIndex) {
            return animation->first.c_str();
        }
    }
    
    return NULL;
}
