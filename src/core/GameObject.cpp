#include "GameObject.h"
#include "components/Components.h"

GameObject::GameObject(artemis::Entity & objectEntity):
entity(objectEntity){
    // Every object in the game will have at least a position
    this->entity.addComponent(new PositionComponent());
    this->entity.refresh();
}

GameObject::~GameObject() {
}

/**
 * Adds a component to the Game Object.
 * @param component     Component derived from artemis::Component.
 */
void GameObject::addComponent(artemis::Component * component) {
    if (component != NULL) {
        this->entity.addComponent(component);
        this->entity.refresh();
    } else {
        std::cout << "Error! - You tried to attach unnitialized component to GameObject " << this->entity.getId() << std::endl;
    }
}

void GameObject::removeComponent(artemis::Component* component) {
    
}

Vector2D GameObject::position() {
    PositionComponent * component = (PositionComponent *)this->entity.getComponent<PositionComponent>();
    
    if (component != NULL) {
        return component->positionVector();
    } else {
        // Something terrible happent!
        std::cout << "Error! - GameObject " << this->entity.getId() << " has no position component." << std::endl;
    }
}

