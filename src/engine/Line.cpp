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
