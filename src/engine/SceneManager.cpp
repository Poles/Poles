#include "engine/SceneManager.h"

using namespace systems;

SceneManager::SceneManager() {
    this->currentScene = NULL;
}

SceneManager::~SceneManager() {
    std::map<std::string, Scene* >::iterator scene;

    for (scene = this->sceneMapper.begin(); scene != this->sceneMapper.end(); ++scene) {
        delete scene->second;
    }

    this->sceneMapper.clear();
}

void SceneManager::onEvent(SDL_Event* event) {
    this->currentScene->onEvent(event);
}

void SceneManager::onRender() {
    this->currentScene->onRender();
}

void SceneManager::onLoop() {
    this->currentScene->onLoop();
}

/**
 * @brief SceneManager::addScene
 * @param scene
 */
void SceneManager::addScene(Scene *scene) {
    if (scene != NULL) {
        std::pair<std::string, Scene* > mappedObject(scene->getName(), scene);

        this->sceneMapper.insert(mappedObject);
    }

    if (this->currentScene == NULL) {
        currentScene = scene;
    }
}

/**
 * @brief SceneManager::changeScene
 * @param sceneName
 * @return
 */
Scene* SceneManager::changeScene(std::string sceneName) {
    std::map<std::string, Scene* >::iterator mappedScene;

    mappedScene = this->sceneMapper.find(sceneName);

    if (mappedScene != this->sceneMapper.end()) {
        this->currentScene = mappedScene->second;
        return this->currentScene;
    } else {
        return NULL;
    }
}

/**
 * @brief SceneManager::deleteScene
 * @param sceneName
 */
void SceneManager::deleteScene(std::string sceneName) {
    std::map<std::string, Scene* >::iterator mappedScene;

    mappedScene = this->sceneMapper.find(sceneName);

    if (mappedScene != this->sceneMapper.end()) {
        delete mappedScene->second;
        this->sceneMapper.erase(mappedScene);
    }
}
