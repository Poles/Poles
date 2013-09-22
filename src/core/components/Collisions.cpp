#include "Collisions.h"

using namespace components;

/**
 * @brief Collisions::Collisions
 */
Collisions::Collisions() {
    this->sprite = NULL;
    this->usePerPixelCollision = false;
}

/**
 * @brief Collisions::Collisions
 * @param x
 * @param y
 * @param w
 * @param h
 */
Collisions::Collisions(const int x, const int y, const int w, const int h):
    collisionBox(x, y, w, h){
    this->sprite = NULL;
    this->usePerPixelCollision = false;
}

/**
 * @brief Collisions::Collisions
 * @param x
 * @param y
 * @param sprite
 */
Collisions::Collisions(const int x, const int y, SpriteRenderer* sprite):
    collisionBox(x, y, sprite->getFrameWidth(), sprite->getFrameHeight()){
    this->sprite = sprite;
    this->usePerPixelCollision = true;
}


/**
 * @brief Collisions::collides
 * @param otherObject
 * @return
 */
bool Collisions::collides(Vector2D& position, Collisions& otherObject, Vector2D& otherObjectPosition) {
    bool boxesCollides;

    boxesCollides = this->collisionBox.collides(position, otherObject.collisionBox, otherObjectPosition);

    if (boxesCollides) {
        if (this->usePerPixelCollision && otherObject.usePerPixelCollision) {
            // If both objects admits per pixel collision, calculate using it
            SDL_Surface* thisSurface = this->sprite->getCurrentAnimationSurface();
            SDL_Surface* otherSurface = otherObject.sprite->getCurrentAnimationSurface();

            return perPixelCollision(thisSurface, position, otherSurface, otherObjectPosition);
        } else {
            return true;
        }
    } else {
        return false;
    }
}

/**
 * @brief Calculates if two images are colliding using pixel-level precision.
 * @param A             Surface representing the pixels of one image.
 * @param positionA     Position of the center point of the image on the screen.
 * @param B             Surface representing the pixels of the other image.
 * @param positionB     Position of the center point of the other image on the screen.
 * @return              True if there is pixels colliding. False otherwise.
 */
bool Collisions::perPixelCollision(SDL_Surface *A, Vector2D &positionA, SDL_Surface *B, Vector2D &positionB) {
    // First we need to calculate the upper left corner of both images to iterate over its pixels
    Vector2D upperLeftA;
    int widthA;
    int heightA;

    widthA = A->w;
    heightA = A->h;
    upperLeftA = positionA - Vector2D(widthA / 2, heightA / 2);

    Vector2D upperLeftB;
    int widthB;
    int heightB;

    widthB = B->w;
    heightB = B->h;
    upperLeftB = positionB - Vector2D(widthB / 2, heightB / 2);

    // We will calculate the overlapping area of the two images so we reduce the area we will iterate over
    SDL_Rect overlappingArea;

    overlappingArea.w = upperLeftA.x() + widthA - upperLeftB.x();
    overlappingArea.x = upperLeftA.x() + widthA - overlappingArea.w;
    overlappingArea.h = upperLeftB.y() + heightB - upperLeftA.y();
    overlappingArea.y = upperLeftB.y() + heightB - overlappingArea.h;

    Uint32 pixelA;
    Uint32 pixelB;
    for (int x = overlappingArea.x; x < (overlappingArea.x + overlappingArea.w); ++x) {
        for (int y = overlappingArea.y; y < (overlappingArea.y + overlappingArea.h); ++y) {
            pixelA = pixelAt(A, pixelCoordinates(x, y, positionA, A));
            pixelB = pixelAt(B, pixelCoordinates(x, y, positionB, B));

            if (pixelA != 0 && pixelB != 0) {
                return true;
            }
        }
    }
    return false;
}

/**
 * @brief Converts a couple of global coordinates to the corresponding local coordinates of the pixels matrix of an image
 * @param x             X global coordinate.
 * @param y             Y global coordinate.
 * @param position      Position of the image in the screen.
 * @param surface       Surface to which we want know what pixels represents the given position.
 * @return              Position inside the pixel matrix of the surface that corresponds to the given coordinates.
 */
Vector2D Collisions::pixelCoordinates(int x, int y, Vector2D &position, SDL_Surface *surface) {
    Vector2D upperLeft = position - Vector2D( surface->w / 2, surface->h / 2 );

    return Vector2D(x, y) - upperLeft;
}
