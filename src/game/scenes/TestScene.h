#ifndef TESTSCENE_H
#define TESTSCENE_H

#include "engine/Scene.h"
#include "engine/Vector2D.h"

class TestScene : public Scene
{
public:
    TestScene();

    void onActivate();

    void onDeactivate();

    void onLoop();

    void onRender();

    void onKeyDown(SDL_Keycode key, Uint16 mod);

private:
    Vector2D cameraPos;
    Vector2D objectPos;
    Vector2D bgPos;
    SDL_Texture* bg;
};

#endif // TESTSCENE_H
