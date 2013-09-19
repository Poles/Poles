#ifndef RENDERINGSYSTEM_H
#define	RENDERINGSYSTEM_H

#include <Artemis/Artemis.h>
#include "../components/Components.h"

using namespace components;

class RenderingSystem : public artemis::EntityProcessingSystem {
public:
    RenderingSystem();
    virtual ~RenderingSystem();
    
    void                                                initialize();
    
    void                                                processEntity(artemis::Entity & e);
    
private:
    artemis::ComponentMapper<Position>         positionMapper;
    artemis::ComponentMapper<SpriteSheetRendererComponent>   spriteMapper;
};

#endif	/* RENDERINGSYSTEM_H */

