#include "Camera.h"
#include "../../game/Game.h"

using namespace components;

Camera::Camera(int mode, int x, int y, int w, int h) {
	this->mode = mode;
	if (mode = POLES_CAMERA_MAIN) {
		this->renderer = createRenderer(Game::getCurrentWindow());
		this->position.setX(x);
		this->position.setY(y);
		this->width = Game::getRenderingContextWidth();
		this->height = Game::getRenderingContextHeight();
	} else {
		// TODO: Create software renderer
	}
}

Camera::~Camera() {
	SDL_DestroyRenderer(this->renderer);
}

SDL_Renderer* Camera::createRenderer(SDL_Window* window) {
	SDL_Renderer * renderer;

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL) {
		SDL_ShowSimpleMessageBox(
			SDL_MESSAGEBOX_ERROR,
			"Camera::Camera(SDL_Renderer* renderer)",
			SDL_GetError(),
			window);
	}

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	return renderer;
}

void Camera::renderScene() {
	if (mode == POLES_CAMERA_MAIN) {
		SDL_RenderPresent(this->renderer);
	} else {
		// Software rendering
	}
}