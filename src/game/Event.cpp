#include "Event.h"

Event::Event() {
}

Event::~Event() {
}

void Event::onEvent(SDL_Event * event) {
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

void Event::onInputBlur() {
    // Pure virtual
}

void Event::onInputFocus() {
    // Pure Virtual
}

void Event::onKeyDown(SDL_Keycode key, Uint16 mod) {
    // Pure Virtual
}

void Event::onKeyUp(SDL_Keycode key, Uint16 mod) {
    // Pure virtual
}

void Event::onMouseFocus() {
    // Pure virtual
}

void Event::onMouseBlur() {
    // Pure virtual
}

void Event::onMouseMove(int mouseX, int mouseY, int relX, int relY, bool left, bool right, bool middle) {
    // Pure virtual
}

void Event::onMouseWheel(bool up, bool down) {
    // Pure virtual
}

void Event::onLeftButtonDown(int mouseX, int mouseY) {
    // Pure virtual
}

void Event::onLeftButtonUp(int mouseX, int mouseY) {
    // Pure virtual
}

void Event::onRightButtonDown(int mouseX, int mouseY) {
    // Pure virtual
}

void Event::onRightButtonUp(int mouseX, int mouseY) {
    // Pure virtual
}

void Event::onMiddleButtonDown(int mouseX, int mouseY) {
    // Pure virtual
}

void Event::onMiddleButtonUp(int mouseX, int mouseY) {
    // Pure virtual
}

void Event::onJoyAxis(Uint8 which, Uint8 axis, Sint16 value) {
    // Pure virtual
}

void Event::onJoyButtonDown(Uint8 which, Uint8 button) {
    // Pure virtual
}

void Event::onJoyButtonUp(Uint8 which, Uint8 button) {
    // Pure virtual
}

void Event::onJoyHat(Uint8 which, Uint8 hat, Uint8 value) {
    // Pure virtual
}

void Event::onJoyBall(Uint8 which, Uint8 ball, Sint16 xrel, Sint16 yrel) {
    // Pure virtual
}

void Event::onMinimize() {
    // Pure virtual
}

void Event::onRestore() {
    // Pure virtual
}

void Event::onResize(int w, int h) {
    // Pure virtual
}

void Event::onExpose() {
    // Pure virtual
}

void Event::onExit() {
    // Pure virtual
}

void Event::onUser(Uint8 type, int code, void* data1, void* data2) {
    // Pure virtual
}
