#include <SDL2/SDL_image.h>
#include <fstream>
#include <sstream>
#include "SpriteSheet.h"
#include "../game/Game.h"

/**
 * 
 * @param filePath
 */
SpriteSheet::SpriteSheet(const char * filePath) {
    // Open Image file
    this->spriteSheet = IMG_LoadTexture(Game::currentRenderer(), filePath);
    
    if (this->spriteSheet == NULL) {
        std::stringstream stream;
        
        stream << "Image " << filePath << " couldn't be loaded." << std::endl << SDL_GetError();
        
        SDL_ShowSimpleMessageBox(
                SDL_MESSAGEBOX_ERROR,
                "ERROR - Sprite Sheet",
                stream.str().c_str(),
                NULL);
    }
    
    SDL_QueryTexture(this->spriteSheet, NULL, NULL, & this->totalWidth, & this->totalHeight);    
    
    // Open JSON file
    Json::Value root;
    Json::Reader reader;
    
    // Find the JSON file (it will have the same name but with the .json extension)
    std::string jsonFilePath(filePath);
    unsigned int lastDotPosition = jsonFilePath.find_last_of(".");
    jsonFilePath = jsonFilePath.substr(0, lastDotPosition);
    jsonFilePath.append(".json");
    
    bool parsingSuccessful;
    std::ifstream jsonStream(jsonFilePath.c_str(), std::ifstream::binary);
    
    parsingSuccessful = reader.parse(jsonStream, root, false);
    
    if (parsingSuccessful == false) {
        std::stringstream stream;
        
        stream << "Missing file or parsing error for JSON " << jsonFilePath;
        
        SDL_ShowSimpleMessageBox(
                SDL_MESSAGEBOX_ERROR,
                "ERROR - Sprite Sheet",
                stream.str().c_str(),
                NULL);
    }
    
    Json::Value animations = root["animations"];
    unsigned int numberOfAnimations = animations.size();
    
    // Reserve memory for all the animations
    this->animations = new std::vector<SpriteAnimation *>(numberOfAnimations);
    
    unsigned int maxNumberOfFrames = 0; // We will need it later
    unsigned int currentNumberOfFrames;
    for (unsigned int currentAnimation = 0; currentAnimation < numberOfAnimations; ++currentAnimation) {
        currentNumberOfFrames = animations[currentAnimation]["frames"].asUInt();
        
        if (currentNumberOfFrames > maxNumberOfFrames) {
            maxNumberOfFrames = currentNumberOfFrames;
        }
    }
    
    // Now we can calculate the width and height of each animation frame
    this->frameWidth = this->totalWidth / maxNumberOfFrames;
    this->frameHeight = this->totalHeight / numberOfAnimations;
    
    // Iterate over the animation information creating SpriteAnimation data
    Json::Value currentAnimation;
    for (unsigned int currentAnimationIndex = 0; currentAnimationIndex < numberOfAnimations; ++currentAnimationIndex) {
        currentAnimation = animations[currentAnimationIndex];
        
        this->animations->at(currentAnimationIndex)
                =
                new SpriteAnimation(
                currentAnimation["name"].asString(),
                this->frameWidth,
                this->frameHeight,
                currentAnimation["frames"].asInt(),
                currentAnimation["frame_rate"].asInt(),
                currentAnimation["oscillate"].asBool());
        
        this->animationsMapper.insert(
                std::pair<std::string, unsigned int>(
                        currentAnimation["name"].asString(),
                        currentAnimationIndex));
    }
}

/**
 * 
 */
SpriteSheet::~SpriteSheet() {
    SDL_DestroyTexture(this->spriteSheet);
    
    for (unsigned int animationIndex = 0; animationIndex < this->animations->size(); ++animationIndex) {
        delete this->animations->at(animationIndex);
    }
    
    this->animations->clear();
    
    delete this->animations;
}

/**
 * Access to an specific animation of the sprite.
 * 
 * It is usually used for sprite[animation][frame].
 * @param animation     Name of the animation.
 * @return              Reference to the animation.
 */
SpriteAnimation & SpriteSheet::operator [](const char * animation) {
    if (animation == NULL) {
        return * (this->animations->at(0));
    } else {
        return * (this->animations->at(this->animationsMapper.find(animation)->second));
    }
}

/**
 * 
 * @return 
 */
SpriteAnimation & SpriteSheet::getDefaultAnimation() {
    return * (this->animations->at(0));
}

/**
 * Access to an specific animation of the sprite.
 * @param animation     Name of the animation.
 * @return              Reference to the animation.
 */
SpriteAnimation & SpriteSheet::getAnimation(const char* animation) {
   return * (this->animations->at(this->animationsMapper.find(animation)->second)); 
}

