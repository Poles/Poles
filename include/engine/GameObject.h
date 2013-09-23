#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include <Artemis/Artemis.h>

// Prototype
class Scene;

class GameObject {
    // We add Scene as a friend class so it can access the constructor and destructor
    friend class Scene;
public:

private:
    GameObject(std::string name, artemis::Entity& entity);

private:
    std::string                         name;
    artemis::Entity&                    entity;
};

#endif // GAMEOBJECT_H
