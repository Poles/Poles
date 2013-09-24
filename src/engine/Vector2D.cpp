#include "engine/Vector2D.h"
#include <sstream>
#include "engine/ExtraTools.h"

/**
 Default constructor. Coordinates are set to 0.
 */
Vector2D::Vector2D() {
    _x = 0.0f;
    _y = 0.0f;
}

/**

 @param x     X coordinate.
 @param y     Y coordinate.
 */
Vector2D::Vector2D(int x, int y)
: _x(x), _y(y) {

}

/**
 Copy constructor.
 @param orig  Vector to copy.
 */
Vector2D::Vector2D(const Vector2D& orig) {
    _x = orig._x;
    _y = orig._y;
}

/**
 Destructor.
 */
Vector2D::~Vector2D() {

}

/**
 Assignment operator.
 @param vector  Vector to copy values from.
 @return        Final vector.
 */
Vector2D& Vector2D::operator =(const Vector2D& vector) {
    _x = vector._x;
    _y = vector._y;
    return *this;
}

/**
 Sum operator.
 @param vector  Vector to sum with this one.
 @return        Final vector.
 */
Vector2D Vector2D::operator +(const Vector2D& vector) {
    return Vector2D(_x + vector._x, _y + vector._y);
}

/**
 Resizes vector by a factor.
 @param f   Resize factor.
 @return    Vector resized.
 */
Vector2D Vector2D::operator *(float f) {
    return Vector2D(_x * f,_y * f);
}

/**
 Subtraction operator.
 @param vector  Vector to subtrate from.
 @return        Final vector.
 */
Vector2D Vector2D::operator -(const Vector2D& vector) {
    return Vector2D(_x - vector._x, _y - vector._y);
}

/**
 Comparison operator.
 @param vector  Vector to compare with.
 @return        true if the vector aren't equal, false otherwise.
 */
bool Vector2D::operator !=(const Vector2D &vector) {
    return _x - vector._x != 0.0f || _y - vector._y != 0.0f;
}

/**
 Comparison operator.
 @param vector  Vector to compare with.
 @return        true if they are equal, false otherwise.
 */
bool Vector2D::operator ==(const Vector2D &vector) {
    return _x - vector._x == 0.0f && _y - vector._y == 0.0f;
}

/**
 Perform the dot product of two vectors.
 @param vector  The other vector to operate with.
 @return        Value resulting of the operation.
 */
int Vector2D::dotProduct(const Vector2D &vector) {
    int result = 0.0;

    result += this->_x * vector._x;
    result += this->_y * vector._y;

    return result;
}

/**
 Length of the vector (without applying the square root to the result).
 @return    Quadratic length.
 */
int Vector2D::lengthQuadratic() {
    return (_x * _x + _y * _y);
}

/**
 Length fo the vector.
 @return    Length.
 */

int Vector2D::length() {
    return squareRoot(_x * _x + _y * _y);
}

/**
 Quadratic distance to other vector.
 @param vector    The other vector.
 @return          Quadratic distance.
 */
int Vector2D::distanceQuadratic(const Vector2D& vector) {
    int Ax,Ay;

    Ax = _x - vector._x;
    Ay = _y - vector._y;

    return (Ax*Ax + Ay*Ay);
}

/**
 Distance to other vector.
 @param vector      The other vector.
 @return            Distante to the other vector.
 */
int Vector2D::distance(const Vector2D& vector) {
    int Ax,Ay;

    Ax = _x - vector._x;
    Ay = _y - vector._y;

    return squareRoot(Ax*Ax + Ay*Ay);
}

/**
 Normalizes the vector to values between 0 and 1.
 */
Vector2D& Vector2D::normalize() {
    int lengthsq = (_x * _x + _y * _y);

    if( lengthsq == 0) {
        _x = 0.0f;
        _y = 0.0f;
        return *this;
    }

    int recip = invSqrt( lengthsq);
    _x *= recip;
    _y *= recip;

    return *this;
}

/**
 Format the values of the vector to represent it as a string.
 @return    String with the forma (x,y).
 */
std::string Vector2D::toString() {
    std::stringstream str;

    str << "(" << _x << "," << _y << ")";

    return str.str();
}
