#ifndef RENDERINGSYSTEM_H
#define	RENDERINGSYSTEM_H

#include <Artemis/Artemis.h>
#include "../components/Components.h"

class RenderingSystem : public artemis::EntityProcessingSystem {
public:
    RenderingSystem();
    virtual ~RenderingSystem();
    
    void                                                initialize();
    
    void                                                processEntity(artemis::Entity & e);
private:
    artemis::ComponentMapper<PositionComponent>         positionMapper;
    artemis::ComponentMapper<SpriteRendererComponent>   spriteMapper;
};

#endif	/* RENDERINGSYSTEM_H */

