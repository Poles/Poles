#include "EventListener.h"

EventListener::EventListener() {
}

EventListener::~EventListener() {
}

void EventListener::onEvent(SDL_Event * event) {
    switch (event->type) {
        case SDL_WINDOWEVENT:
            switch (event->window.type) {
                case SDL_WINDOWEVENT_FOCUS_GAINED:
                    onInputFocus();
                    break;
                    
                case SDL_WINDOWEVENT_FOCUS_LOST:
                    onInputBlur();
                    break;
                    
                case SDL_WINDOWEVENT_ENTER:
                    onMouseFocus();
                    break;
                    
                case SDL_WINDOWEVENT_LEAVE:
                    onMouseBlur();
                    break;
                    
            }
        
        case SDL_KEYDOWN:
            onKeyDown(event->key.keysym.sym, event->key.keysym.mod);
            break;
            
        case SDL_KEYUP:
            onKeyUp(event->key.keysym.sym, event->key.keysym.mod);
            break;
            
        case SDL_MOUSEMOTION:
            onMouseMove(event->motion.x,
                    event->motion.y,
                    event->motion.xrel,
                    event->motion.yrel,
                    (event->motion.state & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0,
                    (event->motion.state & SDL_BUTTON(SDL_BUTTON_RIGHT)) != 0,
                    (event->motion.state & SDL_BUTTON(SDL_BUTTON_MIDDLE)) != 0);
            break;
            
        case SDL_MOUSEBUTTONDOWN:
            switch (event->button.button) {
                case SDL_BUTTON_LEFT:
                    onLeftButtonDown(event->button.x, event->button.y);
                    break;
                    
                case SDL_BUTTON_RIGHT:
                    onRightButtonDown(event->button.x, event->button.y);
                    break;
                    
                case SDL_BUTTON_MIDDLE:
                    onMiddleButtonDown(event->button.x, event->button.y);
                    break;
            }            
            break;
            
        case SDL_MOUSEBUTTONUP:
            switch (event->button.button) {
                case SDL_BUTTON_LEFT:
                    onLeftButtonUp(event->button.x, event->button.y);
                    break;
                    
                case SDL_BUTTON_RIGHT:
                    onRightButtonUp(event->button.x, event->button.y);
                    break;
                    
                case SDL_BUTTON_MIDDLE:
                    onMiddleButtonUp(event->button.x, event->button.y);
                    break;
            }
            
        case SDL_JOYAXISMOTION:
            onJoyAxis(event->jaxis.which, event->jaxis.axis, event->jaxis.value);
            break;
            
        case SDL_JOYBALLMOTION:
            onJoyBall(event->jball.which, event->jball.ball, event->jball.xrel, event->jball.yrel);
            break;
            
        case SDL_JOYHATMOTION:
            onJoyHat(event->jhat.which, event->jhat.hat, event->jhat.value);
            break;
            
        case SDL_JOYBUTTONDOWN:
            onJoyButtonDown(event->jbutton.which, event->jbutton.button);
            break;
            
        case SDL_JOYBUTTONUP:
            onJoyButtonUp(event->jbutton.which, event->jbutton.button);
            break;
            
        case SDL_QUIT:
            onExit();
            break;
            
        case SDL_SYSWMEVENT:
            // Ignore
            break;
            
        case SDL_WINDOWEVENT_RESIZED:
            onResize(event->window.data1, event->window.data2); // TODO: Check this is right
            break;
            
        case SDL_WINDOWEVENT_EXPOSED:
            onExpose();
            break;
            
        default:
            onUser(event->user.type, event->user.code, event->user.data1, event->user.data2);
            break;
    }
}

void EventListener::onInputBlur() {
    // Pure virtual
}

void EventListener::onInputFocus() {
    // Pure Virtual
}

void EventListener::onKeyDown(SDL_Keycode key, Uint16 mod) {
    // Pure Virtual
}

void EventListener::onKeyUp(SDL_Keycode key, Uint16 mod) {
    // Pure virtual
}

void EventListener::onMouseFocus() {
    // Pure virtual
}

void EventListener::onMouseBlur() {
    // Pure virtual
}

void EventListener::onMouseMove(int mouseX, int mouseY, int relX, int relY, bool left, bool right, bool middle) {
    // Pure virtual
}

void EventListener::onMouseWheel(bool up, bool down) {
    // Pure virtual
}

void EventListener::onLeftButtonDown(int mouseX, int mouseY) {
    // Pure virtual
}

void EventListener::onLeftButtonUp(int mouseX, int mouseY) {
    // Pure virtual
}

void EventListener::onRightButtonDown(int mouseX, int mouseY) {
    // Pure virtual
}

void EventListener::onRightButtonUp(int mouseX, int mouseY) {
    // Pure virtual
}

void EventListener::onMiddleButtonDown(int mouseX, int mouseY) {
    // Pure virtual
}

void EventListener::onMiddleButtonUp(int mouseX, int mouseY) {
    // Pure virtual
}

void EventListener::onJoyAxis(Uint8 which, Uint8 axis, Sint16 value) {
    // Pure virtual
}

void EventListener::onJoyButtonDown(Uint8 which, Uint8 button) {
    // Pure virtual
}

void EventListener::onJoyButtonUp(Uint8 which, Uint8 button) {
    // Pure virtual
}

void EventListener::onJoyHat(Uint8 which, Uint8 hat, Uint8 value) {
    // Pure virtual
}

void EventListener::onJoyBall(Uint8 which, Uint8 ball, Sint16 xrel, Sint16 yrel) {
    // Pure virtual
}

void EventListener::onMinimize() {
    // Pure virtual
}

void EventListener::onRestore() {
    // Pure virtual
}

void EventListener::onResize(int w, int h) {
    // Pure virtual
}

void EventListener::onExpose() {
    // Pure virtual
}

void EventListener::onExit() {
    // Pure virtual
}

void EventListener::onUser(Uint8 type, int code, void* data1, void* data2) {
    // Pure virtual
}
