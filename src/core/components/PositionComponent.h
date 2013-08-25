#ifndef POSITIONCOMPONENT_H
#define	POSITIONCOMPONENT_H

#include <Artemis.h>
#include "../Vector2D.h"

class PositionComponent : public artemis::Component {
public:
    PositionComponent();
    PositionComponent(float x, float y);
    virtual ~PositionComponent();
    
private:
    Vector2D position;
};

#endif	/* POSITIONCOMPONENT_H */

