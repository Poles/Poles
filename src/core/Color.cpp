#include "Color.h"
#include <sstream>

Color::Color(){
    this->color.r = 0;
    this->color.g = 0;
    this->color.b = 0;
    this->_a = 255;
}

Color::Color(const int r, const int g, const int b, const int a){
    this->color.r = r;
    this->color.g = g;
    this->color.b = b;
    this->_a = a;
}

Color::Color(const char* hexString, const Uint8 alpha) {
    std::stringstream stream;
    
    stream << std::hex << hexString;
    std::string colorString = stream.str();
    
    // We remove the # character if present
    if (colorString[0] == '#') {
        colorString.erase(0,1);
    }
    
    // We check the size is correct
    if (colorString.size() == 6) {
        std::stringstream redString;
        redString << std::hex << (colorString.substr(0,2));
        
        std::stringstream greenString;
        greenString << std::hex << (colorString.substr(2,2));
        
        std::stringstream blueString;
        blueString << std::hex << (colorString.substr(4,2)); 
        
        unsigned int red;
        unsigned int green;
        unsigned int blue;
        
        redString >> red;
        blueString >> blue;
        greenString >> green;
        
        this->color.r = red;
        this->color.g = green;
        this->color.b = blue;
        this->_a = alpha;
    }
}

Color::Color(const Color & other) {
    this->color = other.color;
    this->_a = other._a;
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
    
    this->_a = value;
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
    return this->_a;
}

SDL_Color Color::toSDLColor(){
    this->color.a = this->_a;
    return this->color;
}

Uint32 Color::toPixelValue(SDL_PixelFormat* format) {
    return SDL_MapRGBA(format, this->color.r, this->color.g, this->color.b, this->_a);
}

const std::string Color::toString() {
    std::stringstream stream;
    
    stream << "red: " << this->color.r
            << " green: " << this->color.g
            << " blue: " << this->color.b
            << " alpha: " << this->_a;
    
    return stream.str();
}

