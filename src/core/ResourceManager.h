#ifndef RESOURCEMANAGER_H
#define	RESOURCEMANAGER_H

#ifdef WINDOWS

#include <direct.h>
#define WORKING_DIR __getcwd

#else

#include <unistd.h>
#define WORKING_DIR getcwd
#define TEXT_DEFAULT_POINTSIZE 16

#endif

#include <cstdio>       // Defines FILENAME_MAX
#include "Sprite.h"
#include <map>
#include <SDL2/SDL_ttf.h>

class ResourceManager {
public:
    ResourceManager *                           instance();
    
    static void                                 initialize();
    
    static Sprite *                             loadImage(const char * name, const char * imagePath, unsigned int animations = 1, unsigned int * framesPerAnimation = NULL);
    static void                                 deleteImage(const char * name);
    static Sprite *                             getSprite(const char * name);
    
    static TTF_Font *                           getFont(const char * fontName);
    
    static void                                 showSpritesDataBase();

private:
    ResourceManager();
    ~ResourceManager();
    
    std::string                                 fixWindowsPath(std::string & path);
    
private:
    static ResourceManager *                    classInstance;
    static std::map<std::string, Sprite * >     images;
    static std::map<std::string, TTF_Font * >   fonts;
    
    static char                                 workingPath[FILENAME_MAX];
};

#endif	/* RESOURCEMANAGER_H */

