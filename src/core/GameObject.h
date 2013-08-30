#ifndef GAMEOBJECT_H
#define	GAMEOBJECT_H

#include <Artemis.h>
#include "Vector2D.h"

class Game;

class GameObject {
    // Game have permission to create Game Objects
    friend class Game;
public:
    
    void                        addComponent(artemis::Component * component);
    void                        removeComponent(artemis::Component * component);
    Vector2D                    position();
    
private:
    // Private constructor to not let the user create GameObjects without using Game::CreateGameObject()
    GameObject(artemis::Entity & objectEntity);
    // Private constructor. User shouldn't be able to delete GameObjects without using Game::deleteGameObject()
    ~GameObject();
    
private:
    artemis::Entity &           entity;

};

#endif	/* GAMEOBJECT_H */

