#ifndef POSITIONCOMPONENT_H
#define	POSITIONCOMPONENT_H

#include <Artemis/Artemis.h>
#include "../Vector2D.h"

namespace components{

class Position : public artemis::Component {
public:
    Position();
    Position(float x, float y);
    
    virtual ~Position() {
        
    }
    
    inline Vector2D             getLocalPosition() { return pos; }
    inline void                 move(Vector2D & velocity) { pos = getPosition() + velocity; }
    inline void                 setPosition(const Vector2D & newPosition) { pos = newPosition; }
    void                        setParentPosition(Position * position);
    void                        removeParentPosition();
    
    Vector2D                    getPosition();
    
private:
    Vector2D                    pos;
    Position *         parentPosition;
};
}

#endif	/* POSITIONCOMPONENT_H */

