#ifndef SCENE_H
#define SCENE_H

#include <string>
#include "engine/EventListener.h"
#include <Artemis/Artemis.h>
#include "engine/GameObject.h"

class Scene : public EventListener {
public:
    Scene(std::string name);

    virtual ~Scene();

    virtual void                        onStart();

    virtual void                        onEnd();

    virtual void                        onLoop();

    virtual void                        onRender() = 0;

    GameObject*                         createGameObject(std::string name);

    void                                destroyGameObject(GameObject*& object);

    inline std::string                  getName() { return name; }

private:
    std::string                         name;   // Name of the Scene

public:
    artemis::World*                     world;  // Artemis systems container
    int                                 idCounter;

};

#endif // SCENE_H
