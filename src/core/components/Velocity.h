#ifndef VELOCITY_H
#define	VELOCITY_H

#include <Artemis/Artemis.h>
#include "../Vector2D.h"

namespace components{

class Velocity : public artemis::Component {
public:
    Velocity() {
        
    }
    
    Velocity(float x, float y) {
        velocity.setX(x);
        velocity.setY(y);
    }
    
    ~Velocity() {
        
    }
    
    void addVelocity(Vector2D & velocity) {
        this->velocity = this->velocity + velocity;
    }
    
    void resetVelocity() {
        velocity.setX(0.0f);
        velocity.setY(0.0f);
    }
    
    inline Vector2D velocityVector() { return velocity; }
        
private:
    Vector2D velocity;
};

}



#endif	/* VELOCITY_H */

