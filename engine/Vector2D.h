#ifndef VECTOR2D_H
#define	VECTOR2D_H

#include <string>

class Vector2D {
public:
								Vector2D();
								Vector2D(float x, float y);
								Vector2D(const Vector2D& orig);
								~Vector2D();
    
	Vector2D&					operator=(const Vector2D& vector);
	Vector2D					operator+(const Vector2D& vector);
	Vector2D					operator*(float f);
	Vector2D					operator-(const Vector2D& vector);
	bool						operator!=(const Vector2D& vector);
	bool						operator==(const Vector2D& vector);
    
	inline float                x() { return _x; }
	inline float                y() { return _y; }
    
	inline void					setX(int x) { _x = x; }
	inline void					setY(int y) { _y = y; }
    
    float                       lengthSquared();
    float                       length();
    float                       distanceSquared(const Vector2D& vector);
    float                       distance(const Vector2D& vector);
    
    Vector2D&                   normalize();
    
    std::string                 toString();
    
private:
    float                       invSqrt(float number);
    float                       sqrt(float number);
    
private:
    float                       _x;
    float                       _y;

};

#endif	/* VECTOR2D_H */

