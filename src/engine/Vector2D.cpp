#include "vector2d.h"
#include <sstream>

/**
 Default constructor. Coordinates are set to 0.
 */
Vector2D::Vector2D()
{
    _x = 0.0f;
    _y = 0.0f;
}

/**
 
 @param x     X coordinate.
 @param y     Y coordinate.
 */
Vector2D::Vector2D(float x, float y)
: _x(x), _y(y)
{

}

/**
 Copy constructor.
 @param orig  Vector to copy.
 */
Vector2D::Vector2D(const Vector2D& orig)
{
    _x = orig._x;
    _y = orig._y;
}

/**
 Destructor.
 */
Vector2D::~Vector2D()
{
}

/**
 Assignment operator.
 @param vector  Vector to copy values from.
 @return        Final vector.
 */
Vector2D& Vector2D::operator =(const Vector2D& vector)
{
    _x = vector._x;
    _y = vector._y;
    return *this;
}

/**
 Sum operator.
 @param vector  Vector to sum with this one.
 @return        Final vector.
 */
Vector2D Vector2D::operator +(const Vector2D& vector)
{
    return Vector2D(_x + vector._x, _y + vector._y);
}

/**
 Resizes vector by a factor.
 @param f   Resize factor.
 @return    Vector resized.
 */
Vector2D Vector2D::operator *(float f)
{
    return Vector2D(_x * f,_y * f);
}

/**
 Subtraction operator.
 @param vector  Vector to subtrate from.
 @return        Final vector.
 */
Vector2D Vector2D::operator -(const Vector2D& vector)
{
    return Vector2D(_x - vector._x, _y - vector._y);
}

/**
 Comparison operator.
 @param vector  Vector to compare with.
 @return        true if the vector aren't equal, false otherwise.
 */
bool Vector2D::operator !=(const Vector2D &vector)
{
    return _x - vector._x != 0.0f || _y - vector._y != 0.0f;
}

/**
 Comparison operator.
 @param vector  Vector to compare with.
 @return        true if they are equal, false otherwise.
 */
bool Vector2D::operator ==(const Vector2D &vector)
{
    return _x - vector._x == 0.0f && _y - vector._y == 0.0f;
}

/**
 Length of the vector (without applying the square root to the result).
 @return    Quadratic length.
 */
float Vector2D::lengthQuadratic()
{
    return (_x * _x + _y * _y);
}

/**
 Length fo the vector.
 @return    Length.
 */

float Vector2D::length()
{
    return sqrt(_x * _x + _y * _y);
}

/**
 Quadratic distance to other vector.
 * @param vector    The other vector.
 * @return          Quadratic distance.
 */
float Vector2D::distanceQuadratic(const Vector2D& vector)
{
    float Ax,Ay;
    
    Ax = _x - vector._x;
    Ay = _y - vector._y;
    
    return (Ax*Ax + Ay*Ay);
}

/**
 Distance to other vector.
 @param vector      The other vector.
 @return            Distante to the other vector.
 */
float Vector2D::distance(const Vector2D& vector)
{
    float Ax,Ay;
    
    Ax = _x - vector._x;
    Ay = _y - vector._y;
    
    return sqrt(Ax*Ax + Ay*Ay);
}

/**
 Normalizes the vector to values between 0 and 1.
 */
Vector2D& Vector2D::normalize()
{
    float lengthsq = (_x * _x + _y * _y);
    
    if( lengthsq == 0) {
        _x = 0.0f;
        _y = 0.0f;
        return *this;
    }
    
    float recip = invSqrt( lengthsq);
    _x *= recip;
    _y *= recip;
    
    return *this;
}

std::string Vector2D::toString()
{
    std::stringstream str;
    
    str << "(" << _x << "," << _y << ")";
    
    return str.str();
}


//----------------------------------------------------------------------------//
/**
 Inverse Square root.
 * @param number    Number to calculate the inverse square root.
 * @return          Inverse square root of the number.
 */
float Vector2D::invSqrt(float number)
{
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y  = number;
    i  = * ( long * ) &y;                       // evil floating point bit level hacking
    i  = 0x5f3759df - ( i >> 1 );               // what the fuck?
    y  = * ( float * ) &i;
    y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
    //  y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed
    return y;
}

/**
 Square root.
 @param x   Number to calculate the square root.
 @return    Square root of the number.
 */
float Vector2D::sqrt(float x)
{
    const float xhalf = 0.5f*x;

    union // get bits for floating value
    {
    float x;
    int i;
    } u;
    u.x = x;
    u.i = 0x5f3759df - (u.i >> 1);  // gives initial guess y0
    return x*u.x*(1.5f - xhalf*u.x*u.x);// Newton step, repeating increases accuracy
}
