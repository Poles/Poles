#ifndef MOVEMENTSYSTEM_H
#define	MOVEMENTSYSTEM_H

#include <Artemis/Artemis.h>
#include "../components/Components.h"

class MovementSystem : public artemis::EntityProcessingSystem {
public:
    MovementSystem();
    virtual ~MovementSystem();
    
    void initialize();
    
    void processEntity(artemis::Entity & e);
    
private:
    artemis::ComponentMapper<PositionComponent> positionMapper;
    artemis::ComponentMapper<VelocityComponent> velocityMapper;

};

#endif	/* MOVEMENTSYSTEM_H */

