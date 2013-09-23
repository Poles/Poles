#ifndef SCENE_H
#define SCENE_H

#include <string>
#include "engine/EventListener.h"
#include <Artemis/Artemis.h>
#include "engine/GameObject.h"
#include <map>

class Scene : public EventListener {
public:
    Scene(std::string name);
    virtual ~Scene();

    virtual void                        onActivate();
    virtual void                        onDeactivate();

    virtual void                        onLoop();
    virtual void                        onRender() = 0;
    GameObject*                         createGameObject(std::string name);
    void                                destroyGameObject(GameObject*& object);
    void                                destroyGameObject(std::string name);

    inline std::string                  getName() { return name; }

private:
    std::string                         name;   // Name of the Scene

public:
    artemis::World*                     world;  // Artemis systems container
    int                                 idCounter;

    std::map<std::string, GameObject* > objectsMapping;

};

#endif // SCENE_H
