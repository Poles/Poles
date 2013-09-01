#ifndef RESOURCEMANAGER_H
#define	RESOURCEMANAGER_H

#include "Sprite.h"
#include <map>

class ResourceManager {
public:
    ResourceManager *                           instance();
    
    static void                                 loadImage(const char * name, const char * imagePath, unsigned int rows = 1, unsigned int columns = 1);
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

