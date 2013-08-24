#ifndef __Poles__Circle__
#define __Poles__Circle__

#include <iostream>
#include <SDL2/SDL.h>
#include "Color.h"
#include "Vector2D.h"
#include "Line.h"

class Circle{
public:
    Circle();
    Circle(const float r);
    Circle(const float x, const float y, const float r);
    ~Circle();
    
    void setColor(Color color) { this->fillColor = color; }
    void setPosition(float x, float y) { this->pos.setX(x); this->pos.setY(y); }
    
    inline Vector2D position() { return this->pos; }
    
    bool collides(const Circle& other);
    bool collides(const Line& line);
    
    void draw(SDL_Renderer* rc);
    
private:
    void setPixel(SDL_Surface *surface, int x, int y, Uint32 pixel);
    
private:
    Color fillColor;
    float radius;
    Vector2D pos;
    SDL_Texture* texture;
};

#endif /* defined(__Poles__Circle__) */
