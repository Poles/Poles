#ifndef	CAMERA_H
#define CAMERA_H


#include <Artemis/Component.h>
#include "../Vector2D.h"
#include <SDL2/SDL.h>

enum{
	POLES_CAMERA_SOFTWARE,	// Used for subcameras
	POLES_CAMERA_MAIN		// The main camera where the heavy rendering will be done
};

namespace components {
	class Camera : public artemis::Component {
	public:
		Camera(int mode, int x = 0, int y = 0, int w = 0, int h = 0);

		virtual ~Camera();

		inline SDL_Renderer* getRenderer() { return this->renderer; }

		inline int getWidth() { return width; }

		inline int getHeight() { return height; }

		inline Vector2D getCorrectionVector() { return Vector2D(width / 2, height / 2); }

		void renderScene();

	private:
		SDL_Renderer* createRenderer(SDL_Window* window);

	private:
		int mode;
		int width;
		int height;
		Vector2D position;
		SDL_Renderer* renderer;
		SDL_Surface* renderingSurface;
	};
}

#endif /* CAMERA_H */