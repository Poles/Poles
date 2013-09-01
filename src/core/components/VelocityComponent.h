#ifndef VELOCITYCOMPONENT_H
#define	VELOCITYCOMPONENT_H

#include <Artemis/Artemis.h>
#include "../Vector2D.h"

class VelocityComponent : public artemis::Component {
public:
    VelocityComponent() {
        
    }
    
    VelocityComponent(float x, float y) {
        velocity.setX(x);
        velocity.setY(y);
    }
    
    ~VelocityComponent() {
        
    }
    
    inline Vector2D velocityVector() { return velocity; }
        
private:
    Vector2D velocity;
};



#endif	/* VELOCITYCOMPONENT_H */

