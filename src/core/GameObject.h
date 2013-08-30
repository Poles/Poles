#ifndef GAMEOBJECT_H
#define	GAMEOBJECT_H

#include <Artemis.h>

class Game;

class GameObject {
    // Let the Game class access the private constructor. This way no one except Game can
    // create GameObjects.
    friend class Game;
public:
    
private:
    // Private constructor to not let the user create GameObjects without using Game::CreateGameObject()
    GameObject(artemis::Entity & entity);
    // Private constructor. User shouldn't be able to delete GameObjects without using Game::deleteGameObject()
    ~GameObject();

};

#endif	/* GAMEOBJECT_H */

