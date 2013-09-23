#include "engine/Game.h"
#include <SDL2/SDL_ttf.h>

#include <iostream>

// ===============================================================//
/* Static declarations */

Window* Game::window = NULL;

/*---------------------*/

Game::Game(std::string name) {
    this->name = name;

    // Initialize SDL and TTF
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
}

Game::~Game() {
    delete window;
}


void Game::createWindow(Uint16 w, Uint16 h, WindowMode mode) {
    window = new Window(this->name, w, h, mode);
}

void Game::createWindow() {
    window = new Window(this->name);
}

void Game::start() {
    window->clear();
    window->draw();
    SDL_Delay(5000);
}


void Game::writeToConsole(std::string text) {
    std::cout << text << std::endl;
}
