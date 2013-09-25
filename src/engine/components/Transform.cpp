#include "engine/components/Transform.h"

using namespace components;

/**
 * @brief Default values Pos = (0,0) Scale = (1,1), rotation = 0.0f, no parent.
 */
Transform::Transform() : scale(1.0f, 1.0f) {
    this->rotation = 0.0f;
    this->parent = NULL;
}

/**
 * @brief Changes the current position.
 * @param x X coordinate.
 * @param y Y coodinate.
 */
void Transform::setPosition(float x, float y) {
    this->position.setX(x);
    this->position.setY(y);
}

/**
 * @brief Changes the current position.
 * @param position  New position of the object.
 */
void Transform::setPosition(Vector2D &position) {
    this->position = position;
}

/**
 * @brief Changes the scale of the object.
 *
 * The width and height of the object will be multiplied by these values, so a value of (2.0f, 1.0f) means
 * the final width of the object will be doubled.
 * @param x     width = width * x.
 * @param y     height = height * y;
 */
void Transform::setScale(float x, float y) {
    this->scale.setX(x);
    this->scale.setY(y);
}

/**
 * @brief Changes the scale of the object.
 *
 * The width and height of the object will be multiplied by these values, so a value of (2.0f, 1.0f) means
 * the final width of the object will be doubled.
 * @param scale     Vector containig the x-axis and y-axis scale factors.
 */
void Transform::setScale(Vector2D &scale) {
    this->scale = scale;
}

/**
 * @brief Changes the rotation of the object.
 *
 * A rotation of 0.0f means the object will render as usual.
 * @param angle     Angle set as the rotation of the object.
 */
void Transform::setRotation(float angle) {
    this->rotation = angle;
}

/**
 * @brief Global position of the object (including its parents position in the hierarchy).
 *
 * This will be the result of adding its parent position to objects position. If the object have no
 * parent, its current position will be the actual global position.
 * @return      Global position.
 */
Vector2D Transform::getPosition() {
    if (parent != NULL) {
        return this->position + this->parent->getPosition();
    } else {
        return this->position;
    }
}

/**
 * @brief Realtive position of the object. If there is no parent assigned, the global and relative postition will be the same.
 * @return  Relative position of the object to its parent (global position if there is no parent).
 */
Vector2D Transform::getRelativePosition() {
    return this->position;
}

/**
 * @brief Scale of the object in the two dimensional axis.
 * @return  Scale of the object.
 */
Vector2D Transform::getScale() {
    return this->scale;
}

/**
 * @brief Rotation of the object relative to its center point.
 * @return  Rotation of the object.
 */
float Transform::getRotation() {
    return this->rotation;
}

/**
 * @brief Moves the object adding the given vector.
 * @param direction Vector containing the direction (and amount) of the movement.
 */
void Transform::move(Vector2D &direction) {
    this->position = this->position + direction;
}

/**
 * @brief Rotates the object, adding the given angle to the current angle of rotation.
 * @param angle     Angle to rotate the object.
 */
void Transform::rotate(float angle) {
    this->rotation = this->rotation + angle;
}

/**
 * @brief Set up another object's Transform component as this component parent.
 *
 * This will make the position of this object relative to the other object's position.
 * The current value of position will be modified to relative coordinates.
 * @param parent    Other object Transform component.
 */
void Transform::setParent(Transform *parent) {
    this->parent = parent;

    // Change from global coordinates to relative coordinates
    Vector2D relativePos;

    relativePos = this->position - parent->getPosition();
    this->position = relativePos;
}

/**
 * @brief Unbinds the position of the object with the position of the parent you previously set.
 *
 * This will modify the current value of position to change to global coordinates instead of relative coordinates.
 */
void Transform::unsetParent() {
    if (this->parent != NULL) {
        // Change from relative to global coodinates
        Vector2D globalPosition;

        globalPosition = this->position + parent->getPosition();
        this->position = globalPosition;
        this->parent = NULL;
    }
}
