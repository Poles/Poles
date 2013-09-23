#ifndef TESTSCENE_H
#define TESTSCENE_H

#include "engine/Scene.h"

class TestScene : public Scene
{
public:
    TestScene();

    void onActivate();

    void onDeactivate();

    void onLoop();

    void onRender();

    void onKeyDown(SDL_Keycode key, Uint16 mod);
};

#endif // TESTSCENE_H
