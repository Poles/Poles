#include <iostream>
#include <SDL.h>

int main(int argc, char** argv)
{
	SDL_Window* window;
	SDL_Renderer* renderer;
    
	// Initializes SDL
	SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO);
    
	// Creates the Window we will use to render
	window = SDL_CreateWindow("Magnet",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              512,512,
                              SDL_WINDOW_SHOWN);
    
	// Creates a new rendering context to draw in and binds it to the window created
	renderer = SDL_CreateRenderer(window,-1,0);
    
	// Sets the drawing color for the renderer
	SDL_SetRenderDrawColor(renderer,255,0,0,255);
    
	// Clears the renderer
	SDL_RenderClear(renderer);
    
	// Sawps the rendering context to our rendering context
	SDL_RenderPresent(renderer);
    
	// Makes SDL wait 5 seconds
	SDL_Delay(5000);
    
	// Frees SDL's resources before closing
	SDL_Quit();
	
	return 0;
}
