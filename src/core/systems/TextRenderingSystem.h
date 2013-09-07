#ifndef TEXTRENDERINGSYSTEM_H
#define	TEXTRENDERINGSYSTEM_H

#include <Artemis/Artemis.h>
#include "../components/Components.h"

class TextRenderingSystem : public artemis::EntityProcessingSystem{
public:
    TextRenderingSystem();
    virtual ~TextRenderingSystem();
    
    void                                                initialize();
    
    void                                                processEntity(artemis::Entity & e);
    
private:
    artemis::ComponentMapper<PositionComponent>         positionMapper;
    artemis::ComponentMapper<TextRendererComponent>     rendererMapper;
};

#endif	/* TEXTRENDERINGSYSTEM_H */

