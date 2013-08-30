#include "ResourceManager.h"

/* STATIC VARIABLES */
ResourceManager * ResourceManager::classInstance = 0;

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

