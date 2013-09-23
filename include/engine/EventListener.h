#ifndef EVENTLISTENER_H
#define	EVENTLISTENER_H

#include <SDL2/SDL.h>


class EventListener {
public:
    EventListener();
    virtual ~EventListener();

    virtual void onEvent(SDL_Event * event);
    virtual void onInputFocus();
    virtual void onInputBlur();
    virtual void onKeyDown(SDL_Keycode key, Uint16 mod);
    virtual void onKeyUp(SDL_Keycode key, Uint16 mod);
    virtual void onMouseFocus();
    virtual void onMouseBlur();
    virtual void onMouseMove(int mouseX, int mouseY, int relX, int relY, bool left, bool right, bool middle);
    virtual void onMouseWheel(bool up, bool down);
    virtual void onLeftButtonDown(int mouseX, int mouseY);
    virtual void onLeftButtonUp(int mouseX, int mouseY);
    virtual void onRightButtonDown(int mouseX, int mouseY);
    virtual void onRightButtonUp(int mouseX, int mouseY);
    virtual void onMiddleButtonDown(int mouseX, int mouseY);
    virtual void onMiddleButtonUp(int mouseX, int mouseY);
    virtual void onJoyAxis(Uint8 which, Uint8 axis, Sint16 value);
    virtual void onJoyButtonDown(Uint8 which, Uint8 button);
    virtual void onJoyButtonUp(Uint8 which, Uint8 button);
    virtual void onJoyHat(Uint8 which, Uint8 hat, Uint8 value);
    virtual void onJoyBall(Uint8 which, Uint8 ball, Sint16 xrel, Sint16 yrel);
    virtual void onMinimize();
    virtual void onRestore();
    virtual void onResize(int w, int h);
    virtual void onExpose();
    virtual void onExit();
    virtual void onUser(Uint8 type, int code, void * data1, void * data2);

private:

};

#endif	/* EVENT_H */
