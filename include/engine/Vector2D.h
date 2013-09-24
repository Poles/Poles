#ifndef VECTOR2D_H
#define	VECTOR2D_H

#include <string>

class Vector2D {
public:
                                Vector2D();
                                Vector2D(int x, int y);
                                Vector2D(const Vector2D& orig);
                                ~Vector2D();

    Vector2D&                   operator=(const Vector2D& vector);
    Vector2D                    operator+(const Vector2D& vector);
    Vector2D                    operator*(float f);
    Vector2D                    operator-(const Vector2D& vector);
    bool                        operator!=(const Vector2D& vector);
    bool                        operator==(const Vector2D& vector);
    int                       dotProduct(const Vector2D& vector);

    inline int                x() { return _x; }
    inline int                y() { return _y; }

    inline void                 setX(int x) { _x = x; }
    inline void                 setY(int y) { _y = y; }

    int                       lengthQuadratic();
    int                       length();
    int                       distanceQuadratic(const Vector2D& vector);
    int                       distance(const Vector2D& vector);

    Vector2D&                   normalize();

    std::string                 toString();

private:
    int                       _x;
    int                       _y;

};

#endif	/* VECTOR2D_H */

