#include "GameThread.h"
#include <QMessageBox>
#include "../src/game/GameStateManager.h"

SDL_Surface * GameThread::rendererSurface = NULL;

GameThread::GameThread():
    Game(),
    QThread(){
    this->running = false;
}

GameThread::~GameThread() {

}

void GameThread::start() {
    this->running = true;
    initialize();
    QThread::start();
}

void GameThread::initialize() {
    // Initialize SDL systems
    int error;

    error = SDL_Init(SDL_INIT_EVERYTHING);

    if (error) {
        QMessageBox messageBox;
        messageBox.setText("Error initializing SDL2.");
        messageBox.exec();
    }

    error = TTF_Init();

    if (error) {
        QMessageBox messageBox;
        messageBox.setText("Error initializing SDL2_ttf.");
        messageBox.exec();
    }

    // Get screen resolution
    SDL_DisplayMode screenDisplayMode;
    error = SDL_GetCurrentDisplayMode(0, & screenDisplayMode);

    if (error) {
        QMessageBox messageBox;
        messageBox.setText("Error getting the screen display mode.");
        messageBox.exec();
    }

    this->renderingContextWidth = screenDisplayMode.w;
    this->renderingContextHeight = screenDisplayMode.h;

    // There will be no window. We will render to a QWidget
    wnd = NULL;

    // We will render to renderer as usual, but the result will be rendered in the surface rendererSurface
    Uint32 redMask, greenMask, blueMask, alphaMask;

    redMask =   0x00ff0000;
    greenMask = 0x0000ff00;
    blueMask =  0x000000ff;
    alphaMask = 0xff000000;

    rendererSurface = SDL_CreateRGBSurface(
                0,
                this->renderingContextWidth,
                this->renderingContextHeight,
                32,
                redMask,
                greenMask,
                blueMask,
                alphaMask);

    if (rendererSurface == NULL) {
        QMessageBox messageBox;
        messageBox.setText("Error creating the software rendering surface.");
        messageBox.exec();
    }
    // Create SDL_Surface for rendering
    renderer = SDL_CreateSoftwareRenderer(rendererSurface);

    if (renderer == NULL) {
        QMessageBox messageBox;
        messageBox.setText(SDL_GetError());
        messageBox.exec();
    }

    SDL_SetRenderDrawColor(renderer, 60, 60, 60, 255);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    loadResources();

    //Set the initial state
    GameStateManager::setGameState(GAMESTATE_INTRO);
}

void GameThread::run() {
    while(running) {
        this->update();
        this->render();
        emit frameReady(static_cast<unsigned char * >(rendererSurface->pixels), renderingContextWidth, renderingContextHeight);
    }
    QThread::run();
}

void GameThread::terminate() {
    this->running = false;
    QThread::terminate();
}
