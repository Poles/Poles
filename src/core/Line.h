#ifndef __Poles__Line__
#define __Poles__Line__

#include <iostream>
#include "Vector2D.h"
#include "Color.h"

class Line {
public:
    Line();
    Line(Vector2D pA, Vector2D pB);
    ~Line();
    
    void setColor(Color c);
    void setPointA(const Vector2D pA);
    void setPointB(const Vector2D pB);
    
    Color color();
    Vector2D pointA();
    Vector2D pointB();
    Vector2D middlePoint();
    
    Vector2D normal();
    void rotate(float r);
    
    void draw(SDL_Renderer* rc);
    
private:
    Vector2D pA;
    Vector2D pB;
    Color lineColor;
};

#endif /* defined(__Poles__Line__) */
