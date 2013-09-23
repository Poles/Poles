#ifndef COLLISIONBOX_H
#define COLLISIONBOX_H

#include "Vector2D.h"
#include <SDL2/SDL.h>
#include "components/Camera.h"
#include "Color.h"

class CollisionBox
{
public:
    CollisionBox();
    CollisionBox(const int x, const int y, const int w, const int h);

    bool collides(Vector2D globalPosition, CollisionBox& other, Vector2D otherGlobalPosition);

    void render(components::Camera * cameraToRender, Vector2D position, Color color = presetColors::COLOR_GREEN);

private:
    Vector2D position;      // Relative to the entity. That means (0,0) is the same position of the entity, not the real (0,0) coordinates.
    int width;
    int height;
};

#endif // COLLISIONBOX_H
