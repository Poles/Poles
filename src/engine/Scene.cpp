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

void Scene::onStart() {

}

void Scene::onEnd() {

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

    // TODO: Add to the Scene objects list

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
