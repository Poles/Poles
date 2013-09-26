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
    void                                setTag(std::string tagName);
    inline std::string                  getTag() { return currentTag; }

    inline std::string                  getName() { return name; }

    template<typename c>
        inline artemis::Component*      getComponent() { return entity.getComponent<c>(); }

    artemis::Component*                 addComponent(artemis::Component* component) { entity.addComponent(component);}

private:
    GameObject(std::string name, artemis::Entity& entity);

private:
    artemis::Entity&                    entity;
    std::string                         name;
    std::string                         currentTag;
};

#endif // GAMEOBJECT_H
