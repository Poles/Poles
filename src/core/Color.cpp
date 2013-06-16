#include "Color.h"

Color::Color(){
    this->color.r = 0;
    this->color.g = 0;
    this->color.b = 0;
    this->color.a = 255;
}

Color::Color(const int r, const int g, const int b, const int a){
    this->color.r = r;
    this->color.g = g;
    this->color.b = b;
    this->color.a = a;
}

void Color::setRed(int value){
    if (value > 255){
        value = 255;
    }
    
    if (value < 0){
      value = 0;
    }
    
    this->color.r = value;
}

void Color::setGreen(int value){
    if (value > 255){
        value = 255;
    }
    
    if (value < 0){
        value = 0;
    }
    
    this->color.g = value;
}

void Color::setBlue(int value){
    if (value > 255){
        value = 255;
    }
    
    if (value < 0){
        value = 0;
    }
    
    this->color.b = value;
}

void Color::setAlpha(int value){
    if (value > 255){
        value = 255;
    }
    
    if (value < 0){
        value = 0;
    }
    
    this->color.a = value;
}

const Uint8 Color::red(){
    return this->color.r;
}

const Uint8 Color::green(){
    return this->color.g;
}

const Uint8 Color::blue(){
    return this->color.b;
}

const Uint8 Color::alpha(){
    return this->color.a;
}

SDL_Color Color::toSDLColor(){    
    return this->color;
}

Uint32 Color::toPixelValue(SDL_PixelFormat* format) {
    return SDL_MapRGBA(format, this->color.r, this->color.g, this->color.b, this->color.a);
}
