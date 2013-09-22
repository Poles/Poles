#include "CollisionBox.h"

CollisionBox::CollisionBox() {
    this->width = 0;
    this->height = 0;
}

CollisionBox::CollisionBox(const int x, const int y, const int w, const int h):
    position(x,y)
{
    this->width = w;
    this->height = h;
}

/**
 * @brief CollisionBox::render
 * @param cameraToRender
 * @param position
 */
void CollisionBox::render(components::Camera *cameraToRender, Vector2D position, Color color) {
   SDL_Renderer* renderer = cameraToRender->getRenderer();

   Vector2D globalPosition = position + this->position;
   Vector2D upperLeftPosition = globalPosition - Vector2D(this->width / 2, this->height / 2);

   SDL_Rect box;

   box.x = upperLeftPosition.x();
   box.y = upperLeftPosition.y();
   box.w = this->width;
   box.h = this->height;

   Uint8 oldRed;
   Uint8 oldGreen;
   Uint8 oldBlue;
   Uint8 oldAlpha;

   SDL_GetRenderDrawColor(renderer, &oldRed, &oldGreen, &oldBlue, &oldAlpha);
   SDL_SetRenderDrawColor(renderer, color.red(), color.green(), color.blue(), color.alpha());

   SDL_RenderDrawRect(renderer, &box);
   SDL_RenderDrawPoint(renderer, globalPosition.x(), globalPosition.y());

   SDL_SetRenderDrawColor(renderer, oldRed, oldGreen, oldBlue, oldAlpha);
}

/**
 * @brief CollisionBox::collides
 * @param otherBox
 * @return
 */
bool CollisionBox::collides(Vector2D globalPosition, CollisionBox& other, Vector2D otherGlobalPosition) {
    Vector2D boxUpperLeftPosition;
    Vector2D otherUpperLeftPosition;

    boxUpperLeftPosition = globalPosition + this->position - Vector2D(this->width / 2, this->height / 2);
    otherUpperLeftPosition = otherGlobalPosition + other.position - Vector2D(other.width / 2, other.height / 2);

    SDL_Rect A;
    SDL_Rect B;

    A.x = boxUpperLeftPosition.x();
    A.y = boxUpperLeftPosition.y();
    A.w = this->width;
    A.h = this->height;

    B.x = otherUpperLeftPosition.x();
    B.y = otherUpperLeftPosition.y();
    B.w = other.width;
    B.h = other.height;

    // If the right side is not beyond the others left side, they aren't colliding
    if (A.x + A.w < B.x) {
        return false;
    }

    // If the left side is not before the other box right side, they aren't colliding
    if (A.x > B.x + B.w) {
        return false;
    }

    // If the bottom side os not less than the other upper side, they aren't colliding
    if (A.y > B.y + B.h) {
        return false;
    }

    // If the upper side is not less than the other bottom side, they aren't colliding
    if (A.y + A.h < B.y) {
        return false;
    }

    // If none of these cases are met, they are colliding
    return true;

}
