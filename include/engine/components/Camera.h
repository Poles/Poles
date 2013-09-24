#ifndef CAMERA_H
#define CAMERA_H

#include <Artemis/Component.h>
#include <SDL2/SDL.h>
#include "engine/Vector2D.h"
#include "engine/Window.h"
#include <list>

#include "engine/components/Renderer.h"

namespace components {

class Camera : public artemis::Component {
public:
    Camera();

    void                                setPosition(int x, int y);
    void                                setIndex(int index);

    inline Vector2D                     getPosition() { return position; }
    inline int                          getIndex() { return index; }

    void                                queueForRender(Renderer* render, Vector2D position);

private:
    Window*                             window;     // Window where the rendering will be done
    int                                 index;      // Used to render the cameras in a given order
    Vector2D                            position;   // Center point where the camera is looking

    std::list<
    std::pair<Vector2D, Renderer* > >   renderingQueue; // Contains the components to be renderized in rendering order

};

}

#endif // CAMERA_H
