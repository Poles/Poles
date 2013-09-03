#ifndef RESOURCEMANAGER_H
#define	RESOURCEMANAGER_H

#ifdef WINDOWS

#include <direct.h>
#define WORKING_DIR __getcwd

#else

#include <unistd.h>
#define WORKING_DIR getcwd

#endif

#include <cstdio>       // Defines FILENAME_MAX
#include "Sprite.h"
#include <map>

class ResourceManager {
public:
    ResourceManager *                           instance();
    
    static void                                 initialize();
    
    static void                                 loadImage(const char * name, const char * imagePath, unsigned int animations = 1, unsigned int * framesPerAnimation = NULL);
    static void                                 deleteImage(const char * name);
    static Sprite *                             getSprite(const char * name);

private:
    ResourceManager();
    ~ResourceManager();
    
    std::string                                 fixWindowsPath(std::string & path);
    
private:
    static ResourceManager *                    classInstance;
    static std::map<const char *, Sprite * >    images;
    
    static char                                 workingPath[FILENAME_MAX];
};

#endif	/* RESOURCEMANAGER_H */

