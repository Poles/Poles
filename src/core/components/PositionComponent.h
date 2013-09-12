#ifndef POSITIONCOMPONENT_H
#define	POSITIONCOMPONENT_H

#include <Artemis/Artemis.h>
#include "../Vector2D.h"

class PositionComponent : public artemis::Component {
public:
    PositionComponent();
    PositionComponent(float x, float y);
    
    virtual ~PositionComponent() {
        
    }
    
    inline Vector2D &           getLocalPosition() { return pos; }
    inline void                 move(Vector2D & velocity) { pos = getLocalPosition() + velocity; }
    inline void                 setPosition(const Vector2D & newPosition) { pos = newPosition; }
    void                        setParentPosition(PositionComponent * position);
    void                        removeParentPosition();
    
    Vector2D                    getPosition();
    
private:
    Vector2D                    pos;
    PositionComponent *         parentPosition;
};

#endif	/* POSITIONCOMPONENT_H */

