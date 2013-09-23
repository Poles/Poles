#ifndef COLLISIONSYSTEM_H
#define COLLISIONSYSTEM_H

#include "../GameObject.h"
#include <list>
#include <vector>

namespace systems {

class CollisionSystem
{
public:
    CollisionSystem();

    void                        registerObject(GameObject* object);

    void                        unregisterObject(GameObject* object);

    std::vector<GameObject* >   checkCollisions(GameObject* object);

private:
    std::list<GameObject* >     collidableObjects;
};

}

#endif // COLLISIONSYSTEM_H
