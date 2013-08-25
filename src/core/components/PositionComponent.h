#ifndef POSITIONCOMPONENT_H
#define	POSITIONCOMPONENT_H

#include <Artemis.h>
#include "../Vector2D.h"

class PositionComponent : public artemis::Component {
public:
    PositionComponent() {
        
    }
    
    PositionComponent(float x, float y) {
        pos.setX(x);
        pos.setY(y);
    }
    
    virtual ~PositionComponent() {
        
    }
    
    inline Vector2D & positionVector() { return pos; }
    inline void move(Vector2D & velocity) { pos = pos + velocity; }
    inline void setPosition(const Vector2D & newPosition) { pos = newPosition; }
    
private:
    Vector2D pos;
};

#endif	/* POSITIONCOMPONENT_H */

