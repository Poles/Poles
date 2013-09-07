#ifndef GAMEOBJECT_H
#define	GAMEOBJECT_H

#include <Artemis/Artemis.h>
#include "Vector2D.h"

class Game;

class GameObject {
    // Game have permission to create Game Objects
    friend class Game;
public:
    void                        setParent(GameObject * parent);
    void                        removeParent();
    void                        addComponent(artemis::Component * component);
    void                        removeComponent(artemis::Component * component);
    Vector2D                    getPosition();
    Vector2D                    getRealPosition();
    
    void                        setPosition(Vector2D & position);
    
    bool                        hasParent();
    
    void                        addForce(Vector2D & force);
    void                        resetForce();
    
    void                        showInfo();
    
private:
    // Private constructor to not let the user create GameObjects without using Game::CreateGameObject()
    GameObject(artemis::Entity & objectEntity);
    // Private constructor. User shouldn't be able to delete GameObjects without using Game::deleteGameObject()
    ~GameObject();
    
private:
    GameObject *                parent;
    artemis::Entity &           entity;

};

#endif	/* GAMEOBJECT_H */

