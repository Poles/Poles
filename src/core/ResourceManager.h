#ifndef RESOURCEMANAGER_H
#define	RESOURCEMANAGER_H

#include "Sprite.h"
#include <map>

class ResourceManager {
public:
    ResourceManager *                           instance();
    
    static void                                 loadImage(const char * name, const char * imagePath, unsigned int animations = 1, unsigned int * framesPerAnimation = NULL);
    static void                                 deleteImage(const char * name);
    static Sprite *                             getSprite(const char * name);

private:
    ResourceManager();
    ~ResourceManager();
    
private:
    static ResourceManager *                    classInstance;
    static std::map<const char *, Sprite * >    images;
};

#endif	/* RESOURCEMANAGER_H */

