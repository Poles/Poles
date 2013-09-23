#include "engine/Game.h"
#include <SDL2/SDL_ttf.h>

#include <iostream>
#include <cmath>

/*------------------------------------*/
/*      Static variables              */

Window* Game::window = NULL;

/*------------------------------------*/

Game::Game(std::string name) {
    this->name = name;
    this->run = false;

    // Initialize SDL and TTF
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    this->currentTime = SDL_GetTicks();
    this->oldTime = 0;
    this->deltaTime = 1.0f;

    this->fpsCurrentTime = SDL_GetTicks();
    this->fpsOldTime = 0;
    this->fps = 0;
    this->fpsCounter = 0;

    this->frameSkip = 0;
    this->frameSkipCurrentTime = SDL_GetTicks();
    this->frameSkipOldTime = 0;
    this->timePerFrame = (Uint32) ((1000.0 / (double)ENGINE_MAX_FPS));
}

Game::~Game() {
    delete window;
}

/**
 * @brief Game::createWindow
 * @param w
 * @param h
 * @param mode
 */
void Game::createWindow(Uint16 w, Uint16 h, WindowMode mode) {
    window = new Window(this->name, w, h, mode);
}

/**
 * @brief Game::createWindow
 */
void Game::createWindow() {
    window = new Window(this->name);
}

/**
 * @brief Game::start
 */
void Game::start() {
    this->run = true;
    mainLoop();
}

/**
 * @brief Game::mainLoop
 */
void Game::mainLoop() {
    while (run) {
        updateDeltaTime();

        // Setup artemis::world.loopStart and artemis::world.setDelta
        // TODO: Waiting for SceneManager

        handleEvents();
        update();
        render();

        manageFramesPerSecond();
        countFramesPerSecond();
    }
}

/**
 * @brief Game::handleEvents
 */
void Game::handleEvents() {

}

/**
 * @brief Game::update
 */
void Game::update() {

}

/**
 * @brief Game::render
 */
void Game::render() {
    this->window->clear();

    // Do rendering

    this->window->draw();

}

/**
 * @brief Game::updateDeltaTime
 */
void Game::updateDeltaTime() {
    this->oldTime = this->currentTime;
    this->currentTime = SDL_GetTicks();
    this->deltaTime = (this->currentTime - this->oldTime) / 1000.0f;
}

/**
 * @brief Game::countFramesPerSecond
 */
void Game::countFramesPerSecond() {
    this->fpsCurrentTime = SDL_GetTicks();
    Uint32 timeElapsed = this->fpsCurrentTime - this->fpsOldTime;

    if (timeElapsed >= 1000) {
        // Reset FPS counting
        this->fpsOldTime = this->fpsCurrentTime;
        this->fps = this->fpsCounter;
        this->fpsCounter = 0;
        std::cout << "Running @" << this->fps << " fps." << std::endl;
    } else {
        this->fpsCounter++;
    }
}

/**
 * @brief Game::manageFramesPerSecond
 */
void Game::manageFramesPerSecond() {
    this->frameSkipOldTime = this->frameSkipCurrentTime;
    this->frameSkipCurrentTime = SDL_GetTicks();    // Total time since the start of the game

    int timeElapsed = (int)this->frameSkipCurrentTime - (int)this->frameSkipOldTime; // Time elapsed since the last frame

    // We are running too fast so we need to make the game wait a bit
    int timeToWait = (int)this->timePerFrame - (int)timeElapsed;
    if (timeToWait > 0) {
        SDL_Delay(timeToWait);
    }
    this->frameSkipCurrentTime = SDL_GetTicks();
}

/**
 * @brief Game::writeToConsole
 * @param text
 */
void Game::writeToConsole(std::string text) {
    std::cout << text << std::endl;
}
