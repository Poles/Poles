#include "engine/GameObject.h"
#include "engine/Scene.h"
#include "engine/components/Transform.h"

/**
 * @brief Creates a new object in the scene.
 * @param name      Name of the object.
 * @param scene     Scene the objects belong to.
 */
GameObject::GameObject(std::string name, artemis::Entity& entity):
    entity(entity)
{
    this->name = name;

    // Every object in the game will have at least spacial information
    this->addComponent(new components::Transform());
}

/**
 * @brief Sets the tag for the object.
 *
 * This is usually used to diferenciate between GameObjects. Common tags are "Player", "Enemy", "UI"...
 * @param tagName   Name of the tag to be applied to the object.
 */
void GameObject::setTag(std::string tagName) {
    this->entity.setTag(tagName);
    this->currentTag = tagName;
}
