#include "CollisionSystem.h"

#include "../../game/Game.h"
#include "../components/Collisions.h"

using namespace systems;

CollisionSystem::CollisionSystem(){
}


/**
 * @brief Adds and object to the list of collidable objects.
 *
 * The system will only check collisions between registered objects.
 * @param object    Object to register as collidable object.
 */
void CollisionSystem::registerObject(GameObject* object) {
    // We first check if the object is already in the list
    std::list<GameObject* >::iterator listObject;

    bool alreadyOnList = false;
    for ( listObject = this->collidableObjects.begin(); listObject != this->collidableObjects.end(); ++listObject) {
        if ( (*listObject) == object) {
            alreadyOnList = true;
        }
    }

    // If is not already on the list, we add it
    if (alreadyOnList == false) {
        this->collidableObjects.push_back(object);
    } else {
        Game::debugMessage("CollisionSystem - Trying to add an object already on the list.");
    }

}

/**
 * @brief Removes an object from the collidable objects list.
 *
 * The object will no longer be checked for collision with other objects, althought he can check collisions with others.
 * @param object    Object we wan't to remove from the collidable objects list.
 */
void CollisionSystem::unregisterObject(GameObject *object) {
    this->collidableObjects.remove(object);
}


/**
 * @brief Checks for collisions with the registered objects.
 * @param object    Object we want to check for collisions.
 * @return          Vector containing a collection of objects that collides with the object.
 */
std::vector<GameObject* > CollisionSystem::checkCollisions(GameObject* object) {
    std::vector<GameObject* > objectsColliding;

    components::Collisions* objectCollisionsComponent;
    components::Collisions* listObjectCollisionsComponent;

    std::list<GameObject* >::iterator listObject;
    for ( listObject = this->collidableObjects.begin(); listObject != this->collidableObjects.end(); ++listObject) {
        // We don't want the object to check collisions with him self!!!
        if ( (*listObject) != object) {
            objectCollisionsComponent = (components::Collisions*) object->getComponent<components::Collisions>();
            listObjectCollisionsComponent = (components::Collisions*)((*listObject)->getComponent<components::Collisions>());

            bool collides;
            Vector2D objectPosition;
            Vector2D otherPosition;

            objectPosition = object->getPositionPerspective();
            otherPosition = (*listObject)->getPositionPerspective();

            collides = objectCollisionsComponent->collides(objectPosition,
                                                           (*listObjectCollisionsComponent),
                                                           otherPosition);

            // If there is a collision, we add it to the collision vector
            if (collides == true) {
                objectsColliding.push_back((*listObject));
            }
        }
    }

    return objectsColliding;
}
