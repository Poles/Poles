#include "ResourceManager.h"

#include <iostream>

/* STATIC VARIABLES */
ResourceManager * ResourceManager::classInstance = 0;
std::map<const char *, Sprite * > ResourceManager::images;

/*------------------*/

ResourceManager::ResourceManager() {
}

ResourceManager::~ResourceManager() {
}

ResourceManager * ResourceManager::instance() {
    if (classInstance == 0) {
        classInstance = new ResourceManager();
    }
    
    return classInstance;
}

/**
 * Loads an image from a file and register it in the Resources System with the given name.
 * @param name          Name used to register the image in the system. You will use this name to refer this image in the future.
 * @param imagePath     Path to the image in your disk drive.
 * @param rows          Number of rows of the Sprite. If it is a single frame Sprite don't specify a value.
 * @param columns       Number of columns of the Sprite. If it is a single frame Sprite don't specify a value.
 */
void ResourceManager::loadImage(const char * name, const char * imagePath, unsigned int animations, unsigned int * framesPerAnimation) {
    if (images.count(name) == 0) {
        Sprite * sprite = new Sprite(imagePath, animations, framesPerAnimation);

        images.insert(std::pair<const char *, Sprite * >(name, sprite));
    } else {
        std::cout << "Error! - ResourceManager: Registering an image with an already used name (" << name << ")" << std::endl;
    }
}

/**
 * Deletes the image from the Resource Systems, freeing its resources.
 * @param name  Name that identifies the image in the system.
 */
void ResourceManager::deleteImage(const char * name) {
    std::map<const char *, Sprite * >::iterator image;
    
    image = images.find(name);
    
    if (image != images.end()) {
        Sprite * sprite = image->second;
        
        images.erase(image);
        
        delete sprite;
    } else {
        std::cout << "Error! - ResourceManager: Trying to delete nonexistent image (" << name << ")" << std::endl;
    }
}

/**
 * Access to an image loaded in the system.
 * @param name  Name that identifies the image in the system.
 * @return      Pointer to the image or NULL if it is not present on the system.
 */
Sprite * ResourceManager::getSprite(const char* name) {
    std::map<const char *, Sprite * >::iterator sprite;
    
    sprite = images.find(name);
    
    if (sprite != images.end()) {
        return sprite->second;
    } else {
        return NULL;
    }
}
