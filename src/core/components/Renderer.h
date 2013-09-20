#ifndef RENDERER_H
#define RENDERER_H

#include <Artemis/Component.h>
#include "../Vector2D.h"

namespace components {

class Renderer : public artemis::Component {
public:
    Renderer() { }
    virtual ~Renderer() { }

    virtual void render(Vector2D& position) = 0;

protected:
};

}

#endif // RENDERER_H
