#ifndef RENDERIZABLEASSET_H
#define RENDERIZABLEASSET_H

#include <string>
#include "engine/Window.h"
#include "engine/Vector2D.h"

namespace assets {

class RenderizableAsset {
public:
    RenderizableAsset(std::string name);

    virtual void render(SDL_Renderer* renderer, Vector2D position, Vector2D scale, float rotation) = 0;

protected:
    std::string                         name;
};

}

#endif // RENDERIZABLEASSET_H
