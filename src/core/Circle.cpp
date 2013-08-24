#include "Circle.h"

/**
 
 */
Circle::Circle() {
    radius = 0.0f;
    pos.setX(0);
    pos.setY(0);
    
    this->texture = NULL;
}

/**
 
 @param r
 */
Circle::Circle(const float r) {
    this->radius = 0.0f;
    this->pos.setX(0);
    this->pos.setY(0);
    
    this->texture = NULL;
}

/**
 
 @param x
 @param y
 @param r
 */
Circle::Circle(const float x, const float y, const float r) {
    this->radius = r;
    this->pos.setX(x);
    this->pos.setY(y);
    
    this->texture = NULL;
}

/**
 
 */
Circle::~Circle() {
    SDL_DestroyTexture(this->texture);
}

/**
 
 @param other
 */
bool Circle::collides(const Circle &other) {
    int distance = this->pos.distanceQuadratic(other.pos) - (pow(this->radius,2) + pow(other.radius,2));
    
    if (distance <= 0) {
        return true;
    }
    
    return false;
}

/**
 
 @param rc
 @param pos
 */
void Circle::draw(SDL_Renderer *rc) {    
    // If it isn't created before creates now the texture to render
    if (this->texture == NULL) {
        // Create the texture with the proper format
        this->texture = SDL_CreateTexture(rc, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING,
                                          this->radius * 2, this->radius * 2);
        
        if (this->texture == NULL) {
            std::cout << "Circle::Error creating the texture: " << SDL_GetError() << std::endl;
        }
        
        SDL_Surface* surface = NULL;
        surface = SDL_CreateRGBSurface(SDL_SWSURFACE, this->radius * 2, this->radius * 2, 32,
                                       0xFF000000,  // Red mask
                                       0x00FF0000,  // Green mask
                                       0x0000FF00,  // Blue mask
                                       0x000000FF); // Alpha mask        
        if (surface == NULL) {
            std::cout << "Circle::Error creating the surface: " << SDL_GetError() << std::endl;
        }        
        
        SDL_LockTexture(this->texture, NULL, &surface->pixels, &surface->pitch);
        
        //static const int BPP = 4;
        //
        //double r = (double)this->radius;
        //int cx = this->pos.x();
        //int cy = this->pos.y();
        //
        //for (double dy = 1; dy <= r; dy += 1.0)
        //{
        //    double dx = floor(sqrt((2.0 * r * dy) - (dy * dy)));
        //    int x = cx - dx;
        //    
        //    // Grab a pointer to the left-most pixel for each half of the circle
        //    Uint8 *target_pixel_a = (Uint8 *)surface->pixels + ((int)(cy + r - dy)) * surface->pitch + x * BPP;
        //    Uint8 *target_pixel_b = (Uint8 *)surface->pixels + ((int)(cy - r + dy)) * surface->pitch + x * BPP;
        //    
        //    Uint32 pixel = this->fillColor.toPixelValue(surface->format);
        //    
        //    for (; x <= cx + dx; x++)
        //    {
        //        *(Uint32 *)target_pixel_a = pixel;
        //        *(Uint32 *)target_pixel_b = pixel;
        //        target_pixel_a += BPP;
        //        target_pixel_b += BPP;
        //    }
        //}
        
        SDL_UnlockTexture(this->texture);        
    }
    
    SDL_Rect rect;
    rect.x = this->pos.x() - this->radius;
    rect.y = this->pos.y() - this->radius;
    rect.w = this->radius * 2;
    rect.h = this->radius * 2;
    
    SDL_RenderCopy(rc, this->texture, NULL, &rect); //TODO: This fails sometimes for no reason...
}

/**
 Draw a pixel in a surface.
 @param surface Surfare where the pixel will be drawn.
 @param x   x coord. of the pixel.
 @param y   y coord. of the pixel.
 @param pixel   Pixel to draw. It is usually given by SDL_MapRGB(format, R,G,B,A).
 */
void Circle::setPixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
    Uint8 *target_pixel = (Uint8 *)surface->pixels + y * surface->pitch + x * 4;
    *(Uint32 *)target_pixel = pixel;
}
