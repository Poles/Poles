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

        for (std::list<Renderer *>::iterator currentRenderer = this->renderingQueue.begin(); currentRenderer != this->renderingQueue.end(); ++currentRenderer) {
            (*currentRenderer)->render((*currentRenderer)->getRenderingPosition());
        }

		SDL_RenderPresent(this->renderer);
	} else {
		// Software rendering
    }

    std::cout << "Clearing rendering queue with " << this->renderingQueue.size() << " elements." << std::endl;

    this->renderingQueue.clear();
}

/**
 * @brief Adds the renderer component to the queue to wait to be rendered in the right moment (depending on its parallax index).
 * @param render
 */
void Camera::queueForRendering(Renderer *render) {
    if (this->renderingQueue.size() == 0) {
        this->renderingQueue.push_back(render);
    } else {
        std::list<Renderer* >::iterator currentRender;
        bool inserted = false;

        // We find the position in the queue where this renderer should be (depending of his parallax index)
        currentRender = this->renderingQueue.begin();
        while (inserted == false && currentRender != this->renderingQueue.end()) {
            if ((*currentRender)->getParallaxIndex() < render->getParallaxIndex()) {
                ++currentRender;
            } else {
                inserted = true;
            }
        }
        this->renderingQueue.insert(currentRender, render);

    }
}
