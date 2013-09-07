#include "ResourceManager.h"

#include <iostream>
#include <sstream>

/* STATIC VARIABLES */
ResourceManager * ResourceManager::classInstance = 0;
std::map<std::string, Sprite * > ResourceManager::images;
char ResourceManager::workingPath[FILENAME_MAX];
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

void ResourceManager::initialize() {
    // We load the current working path
    WORKING_DIR(workingPath, sizeof(workingPath));
}

/**
 * Loads an image from a file and register it in the Resources System with the given name.
 * @param name          Name used to register the image in the system. You will use this name to refer this image in the future.
 * @param imagePath     Path to the image in your disk drive.
 * @param rows          Number of rows of the Sprite. If it is a single frame Sprite don't specify a value.
 * @param columns       Number of columns of the Sprite. If it is a single frame Sprite don't specify a value.
 */
Sprite * ResourceManager::loadImage(const char * name, const char * imagePath, unsigned int animations, unsigned int * framesPerAnimation) {
    Sprite * sprite = NULL;
    if (images.count(name) == 0) {
        std::string imageAbsolutePath;
        imageAbsolutePath.append(workingPath);
        imageAbsolutePath.append("/assets/");
        imageAbsolutePath.append(imagePath);

#ifdef _WIN64
      imageAbsolutePath = classInstance->fixWindowsPath(imageAbsolutePath);
#elif _WIN32
      imageAbsolutePath = classInstance->fixWindowsPath(imageAbsolutePath);
      
#elif __linux
      // Linux don't need anything
#elif __APPLE__
      // Path to Contents/Resources inside the .app should be added
#endif
        
        Sprite * sprite = new Sprite(imageAbsolutePath.c_str(), animations, framesPerAnimation);

        images.insert(std::pair<std::string, Sprite * >(std::string(name), sprite));
    } else {
        std::cout << "Error! - ResourceManager: Registering an image with an already used name (" << name << ")" << std::endl;
    }
    
    return sprite;
}

std::string ResourceManager::fixWindowsPath(std::string & path) {
    std::string windowsPath(path);
    
    for (int characterIndex = 0; characterIndex < path.length(); characterIndex++) {
        if (windowsPath[characterIndex] == '/') {
            windowsPath.replace(characterIndex, 1, "\\");
        }
    }
    return windowsPath;
}

/**
 * Deletes the image from the Resource Systems, freeing its resources.
 * @param name  Name that identifies the image in the system.
 */
void ResourceManager::deleteImage(const char * name) {
    std::map<std::string, Sprite * >::iterator image;
    
    image = images.find(std::string(name));
    
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
Sprite * ResourceManager::getSprite(const char * name) {
    std::map<std::string, Sprite * >::iterator sprite;
    
    sprite = images.find(std::string(name));
    
    if (sprite != images.end()) {
        return sprite->second;
    } else {
        std::stringstream str;
        
        str << "Unable to find image " << name << " in the Sprites' data base.\n Have you loaded it before using?";
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
                "Resource Manager",
                str.str().c_str(),
                NULL);
        return NULL;
    }
}

void ResourceManager::showSpritesDataBase() {
    std::stringstream str;
    
    for (std::map<std::string, Sprite * >::iterator sprite = images.begin(); sprite != images.end(); sprite++) {
        str << "[" << sprite->first << "] = " << sprite->second << std::endl;
    }
    
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
            "Resource Manager",
            str.str().c_str(),
            NULL);
}
