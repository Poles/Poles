#include "engine/Scene.h"

Scene::Scene(std::string name):
    name(name)
{
    // Setup Artemis systems
    world = new artemis::World();

    this->idCounter = 0;
}

Scene::~Scene() {
    delete this->world;
}

void Scene::onActivate() {

}

void Scene::onDeactivate() {

}

void Scene::onLoop() {
    world->loopStart();
}

void Scene::onRender() {

}

/**
 * @brief Scene::createGameObject
 * @param name
 * @return
 */
GameObject* Scene::createGameObject(std::string name) {
    GameObject* object;

    artemis::Entity& objectEntity = world->createEntity();
    object = new GameObject(name, objectEntity);

    std::pair<std::string, GameObject* > objectMapped(name, object);
    this->objectsMapping.insert(objectMapped);

    return object;
}

/**
 * @brief Scene::destroyGameObject
 * @param object
 */
void Scene::destroyGameObject(GameObject*& object) {
    world->deleteEntity(object->entity);
    delete object;
    object = NULL;
}

/**
 * @brief Scene::destroyGameObject
 * @param name
 */
void Scene::destroyGameObject(std::string name) {
    std::map<std::string, GameObject* >::iterator object;

    object = this->objectsMapping.find(name);

    if (object != this->objectsMapping.end()) {
        this->objectsMapping.erase(object);
    }
}
