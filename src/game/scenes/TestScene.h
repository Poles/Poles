#ifndef TESTSCENE_H
#define TESTSCENE_H

#include "engine/Scene.h"
#include "engine/Vector2D.h"

class TestScene : public Scene
{
public:
    TestScene();

    virtual ~TestScene();

    void onActivate();

    void onDeactivate();

    void onLoop();

    void onRender();

    void onKeyDown(SDL_Keycode key, Uint16 mod);

private:
    GameObject* background;
    GameObject* reference;
};

#endif // TESTSCENE_H
