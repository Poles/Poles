#include "ResourceManager.h"

#include <iostream>
#include <sstream>
#include <json/json.h>

/* STATIC VARIABLES */
ResourceManager * ResourceManager::classInstance = 0;
std::map<std::string, SpriteSheet *> ResourceManager::spriteSheetMapper;
std::map<std::string, TTF_Font * > ResourceManager::fonts;
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

void ResourceManager::freeAllResources() {
    // Free all SpriteSheets
    std::map<std::string, SpriteSheet *>::iterator sprite;
    for (sprite = spriteSheetMapper.begin(); sprite != spriteSheetMapper.end(); ++sprite) {
        delete sprite->second;
    }

    spriteSheetMapper.clear();

    std::map<std::string, TTF_Font *>::iterator font;
    for (font = fonts.begin(); font != fonts.end(); ++font) {
        TTF_CloseFont(font->second);
    }

    fonts.clear();
}

std::string ResourceManager::getAssetsFolderPath() {
    std::string assetsPath;
    
    assetsPath.append(workingPath);
    assetsPath.append("/assets/");

#ifdef _WIN64
    return classInstance->fixWindowsPath(assetsPath);
#elif _WIN32
    return classInstance->fixWindowsPath(assetsPath);
#elif __linux
    return assetsPath;
#elif __APPLE__
    // TODO
    return assetsPath;
#endif
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
 * 
 * @param fontName
 * @return 
 */
TTF_Font * ResourceManager::getFont(const char * fontName) {
    // Search for the font in the already loaded fonts
    std::map<std::string, TTF_Font * >::iterator font;
    
    font = fonts.find(fontName);
    
    if (font != fonts.end()) {
        return font->second;
    } else {
        // Load the font because it isn't present in the fonts data base
        std::string fontPath;
        
        fontPath.append(workingPath);
        fontPath.append("/assets/fonts/");
        fontPath.append(fontName);
        fontPath.append(".ttf");
        
#ifdef _WIN64
        fontPath = classInstance->fixWindowsPath(fontPath);
#elif _WIN32
        fontPath = classInstance->fixWindowsPath(fontPath);
#elif __linux
      // Linux don't need anything
#elif __APPLE__
      // Path to Contents/Resources inside the .app should be added
#endif
        if (!TTF_WasInit()) {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Font loading", "Error loading font. SDL_ttf is not initialized.", NULL);
        }
        TTF_Font * fontFile = TTF_OpenFont(fontPath.c_str(), TEXT_DEFAULT_POINTSIZE);
        
        if (fontFile == NULL) {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Resource Manager", TTF_GetError(), NULL);
            return NULL;
        }

        fonts.insert(std::pair<std::string, TTF_Font *>(std::string(fontName), fontFile));
        
        return fontFile;
    }
}

/**
 * 
 * @param name
 * @return 
 */
SpriteSheet * ResourceManager::getSpriteSheet(const char * name) {
    // Check if the image is already loaded
    std::map<std::string, SpriteSheet *>::iterator spriteFound;
    
    spriteFound = spriteSheetMapper.find(name);
    
    if (spriteFound != spriteSheetMapper.end()) {
        return spriteFound->second;
    }
    
    // Sprite sheet is not loaded, so we need to load it
    std::string spriteFilePath;
    
    spriteFilePath.append(workingPath);
    spriteFilePath.append("/assets/images/");
    spriteFilePath.append(name);
    
    // Check if the format is specified. If not, use .png as default
    if (spriteFilePath.find_last_of(".") == spriteFilePath.npos) {
        spriteFilePath.append(".png");
    }
    
#ifdef  _WIN64
    spriteFilePath = classInstance->fixWindowsPath(spriteFilePath);
#elif   _WIN32
    spriteFilePath = classInstance->fixWindowsPath(spriteFilePath);
#elif   __linux
    // Nothing to do
#elif   __APPLE__
    // Append the "Contents/Resources" string
#endif
    
    SpriteSheet * spriteSheet = new SpriteSheet(spriteFilePath.c_str());
    
    // Generate name for the SpriteSheet mapper
    std::string spriteSheetName(name);
    spriteSheetName = spriteSheetName.substr(0, spriteSheetName.find_last_of("."));
    
    spriteSheetMapper.insert(std::pair<std::string, SpriteSheet *>(spriteSheetName, spriteSheet));
    
    return spriteSheet;
}


/**
 * @brief ResourceManager::deleteSpriteSheet
 * @param name
 */
void ResourceManager::deleteSpriteSheet(const char* name) {
    std::map<std::string, SpriteSheet* >::iterator spriteFound;

    spriteFound = spriteSheetMapper.find(name);

    if (spriteFound != spriteSheetMapper.end()) {
        delete spriteFound->second;
        spriteSheetMapper.erase(spriteFound);
    }
}
