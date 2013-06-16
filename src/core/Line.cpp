#include "Line.h"

/**
 
 */
Line::Line() {
    
}

/**
 
 @param pA
 @param pB
 */
Line::Line(Vector2D pA, Vector2D pB) {
    this->pA = pA;
    this->pB = pB;
}

/**
 
 */
Line::~Line() {
    
}

Vector2D Line::pointA() {
    return this->pA;
}

Vector2D Line::pointB() {
    return this->pB;
}

Vector2D Line::middlePoint() {
    int x = this->pA.x() + this->pB.x();
    int y = this->pA.y() + this->pB.y();
    
    return Vector2D(x / 2, y / 2);
}

/**
 
 @param pA
 */
void Line::setPointA(const Vector2D pA) {
    this->pA = pA;
}

/**
 
 @param pB
 */
void Line::setPointB(const Vector2D pB) {
    this->pB = pB;
}

/**
 
 @param c
 */
void Line::setColor(Color c) {
    this->lineColor = c;
}

void Line::rotate(float r) {
    // TODO
}

/**
 
 @return Normal vector from this line.
 */
Vector2D Line::normal() {    
    Vector2D dir = this->pA - this->pB;
    int x = dir.y();
    int y = (-1) * dir.x();
    
    return Vector2D(x,y).normalize();
}

/**
 
 */
void Line::draw(SDL_Renderer* rc) {
    Uint8 oldRed;
    Uint8 oldGreen;
    Uint8 oldBlue;
    Uint8 oldAlpha;
    
    SDL_GetRenderDrawColor(rc, &oldRed, &oldGreen, &oldBlue, &oldAlpha);
    
    SDL_SetRenderDrawColor(rc,
                           this->lineColor.red(), this->lineColor.green(), this->lineColor.blue(),
                           this->lineColor.alpha());
    
    SDL_RenderDrawLine(rc, this->pA.x(), this->pA.y(), this->pB.x(), this->pB.y());
    
    SDL_SetRenderDrawColor(rc, oldRed, oldGreen, oldBlue, oldAlpha);
}
