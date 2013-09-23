#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "engine/Scene.h"
#include <map>
#include <SDL2/SDL.h>

namespace systems {

class SceneManager {
public:
    SceneManager();
    virtual ~SceneManager();

    void                                onEvent(SDL_Event* event);
    void                                onLoop();
    void                                onRender();

    Scene*                              changeScene(std::string sceneName);
    void                                addScene(Scene* scene);
    void                                deleteScene(std::string sceneName);

private:
    Scene*                              currentScene;
    std::map<std::string, Scene* >      sceneMapper;
};
}

#endif // SCENEMANAGER_H
