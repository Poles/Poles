#ifndef COLLISIONS_H
#define COLLISIONS_H

#include <Artemis/Component.h>
#include "../CollisionBox.h"
#include "SpriteRenderer.h"
#include <SDL2/SDL.h>

namespace components {

class Collisions : public artemis::Component {
public:
    Collisions();
    Collisions(const int x, const int y, const int w, const int h);
    Collisions(const int x, const int y, SpriteRenderer* sprite);

    bool                        collides(Vector2D &position, Collisions& otherObject, Vector2D &otherObjectPosition);

    inline CollisionBox         getCollisionBox() { return collisionBox; }

    inline void                 setCollisionBox(CollisionBox box) { this->collisionBox = box; }

private:
    bool                        perPixelCollision(SDL_Surface* A, Vector2D& positionA, SDL_Surface* B, Vector2D& positionB);
    inline Uint32               pixelAt(SDL_Surface* surface, int x, int y) { return ((Uint32*)surface->pixels)[ y * surface->w + x ]; }
    inline Uint32               pixelAt(SDL_Surface *surface, Vector2D pos) { return ((Uint32*)surface->pixels)[(int)pos.y() * surface->w + (int)pos.x()]; }
    Vector2D                    pixelCoordinates(int x, int y, Vector2D& position, SDL_Surface* surface);

    int                         max(int a, int b);
    int                         min(int a, int b);

private:
    CollisionBox                collisionBox;
    SpriteRenderer*             sprite;
    bool                        usePerPixelCollision;
};

}

#endif // COLLISIONS_H
