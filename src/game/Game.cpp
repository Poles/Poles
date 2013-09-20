#include "Game.h"
#include <math.h>
#include <Artemis/SystemManager.h>
#include <Artemis/EntityManager.h>
#include <Artemis/Entity.h>
#include "../core/ResourceManager.h"
#include "GameStateManager.h"
#include <SDL2/SDL_ttf.h>
#include <sstream>

/* STATIC VARIABLES */
artemis::World Game::world;
artemis::SystemManager * Game::systemManager = world.getSystemManager();
artemis::EntityManager * Game::entityManager = world.getEntityManager();

SDL_Renderer * Game::renderer = NULL;
SDL_Window * Game::wnd = NULL;
GameObject * Game::mainCameraObject = NULL;
components::Camera* Game::mainCamera = NULL;
bool Game::run;

int Game::renderingContextWidth = 0;
int Game::renderingContextHeight = 0;
/*------------------*/


Game::Game() {
    run = false;
    
    this->timeLastFrame = 0;
    this->timePerFrame = (Uint32) (((double)1 / (double)FPS_MAX) * 1000);
    this->frameSkip = 0;
    this->fps = 0;
    this->timeLastFPSRecord = SDL_GetTicks();
    
    this->showFPS = false;
    
    /* ARTEMIS */
    this->movementSystem = (MovementSystem *)systemManager->setSystem(new MovementSystem());
    this->renderingSystem = (RenderingSystem *)systemManager->setSystem(new RenderingSystem());
    this->textRenderingSystem = (TextRenderingSystem *)systemManager->setSystem(new TextRenderingSystem());
    
    systemManager->initializeAll();
}

Game::~Game() {
    // Free any SDL resource used
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(this->wnd);

    Game::destroyGameObject(mainCameraObject);

    TTF_Quit();
    SDL_Quit();
}

void Game::start() {
    run = true;
    this->initialize();
    this->mainLoop();
}

void Game::exit() {
    run = false;
}

void Game::initialize() {
    int error;
    
    error = SDL_Init(SDL_INIT_EVERYTHING);
    
    if (error != 0) {
        std::cout << SDL_GetError() << std::endl;
    }
    
    SDL_DisplayMode mode;
    error = SDL_GetCurrentDisplayMode(0, &mode);
    
    if (error != 0) {
        std::cout << SDL_GetError() << std::endl;
    }
    
    /* TTF */
    error = TTF_Init();
    
    if (error != 0) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL2_TTF Error!", TTF_GetError(), NULL);
    }
    
    // Scalated resolution for testing porpuses. Remove * 0.75 for release
//    int w = mode.w * 0.75;
//    int h = mode.h * 0.75;
//    int windowMode = SDL_WINDOW_SHOWN;
    int w = mode.w;
    int h = mode.h;
    int windowMode = SDL_WINDOW_FULLSCREEN_DESKTOP;
    
    renderingContextWidth = w;
    renderingContextHeight = h;

    wnd = SDL_CreateWindow(GAME_NAME,
                                 SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                 w,h,
                                 windowMode);
    
    mainCameraObject = createGameObject();
    mainCameraObject->addComponent(new components::Velocity());
    mainCamera = (components::Camera*)mainCameraObject->addComponent(new components::Camera(POLES_CAMERA_MAIN));

    GameStateManager::setGameState(GAMESTATE_PARALLAX_TEST);
}

void Game::mainLoop() {
    while (run) {
        this->handleEvents();
        this->update();
        this->render();
    }
}

/**
 * 
 */
void Game::update() {
    world.loopStart();
    world.setDelta(0.0016f);    // Why this value?

    /* ARTEMIS */
    this->movementSystem->process();
    /*---------*/

    GameStateManager::onLoop();
}

/**
 * 
 */
void Game::render() {
    if (this->frameSkip == 0) {
        SDL_RenderClear(mainCamera->getRenderer());

        this->renderingSystem->process();
        this->textRenderingSystem->process();

        GameStateManager::onRender();

        mainCamera->renderScene();

        this->manageFPS();
    }
    this->countFSP();
}

/**
 * 
 */
void Game::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        // Pass to the state manager so it can send the event to the current state
        GameStateManager::onEvent(&event);

        // Pass the evento to the game. It may want to do something as well
        this->onEvent(&event);
    }
}

void Game::manageFPS() {
    Uint32 currentTime = SDL_GetTicks();    // Total time since the start of the game
    this->timeLastFrame = currentTime;
    
    Uint32 timeElapsed = currentTime - this->timeLastFrame; // Time elapsed since the last frame
    
    if (timeElapsed > this->timePerFrame) {
        // We are running slowly, so we will skip rendering some frames
        this->frameSkip = floor(timeElapsed / this->timePerFrame);
    } else {
        // We are running too fast so we need to make the game wait a bit
        Uint32 timeToWait = this->timePerFrame - timeElapsed;
        SDL_Delay(timeToWait);
    }
}

void Game::countFSP() {
    Uint32 currentTime = SDL_GetTicks();
    Uint32 timeElapsed = currentTime - this->timeLastFPSRecord;
    
    if (timeElapsed >= 1000) {
        // Reset FPS counting
        if (this->showFPS) {
            updateFPSCounter();
        }
        this->fps = 0;
        this->timeLastFPSRecord = currentTime;
    } else {
        this->fps++;
    }
}

/**
 * Creates a new Game Object to be used in the game.
 * 
 * It is initialized inside the Artemis-Cpp's entity systems and it is ready
 * to attach components as needed. To destroy it use Game::destroyGameObject(GameObject * object).
 * @return 
 */
GameObject * Game::createGameObject() {
    artemis::Entity & objectEntity = world.createEntity();
    
    GameObject * object = new GameObject(objectEntity);
    
    return object;
}

void Game::destroyGameObject(GameObject * object) {
    world.deleteEntity(object->entity);
    
    delete object;
    object = NULL;
}

SDL_Renderer * Game::currentRenderer() {
    //return renderer;
    return mainCamera->getRenderer();
}

SDL_Window* Game::getCurrentWindow() {
    return wnd;
}

void Game::onKeyDown(SDL_Keycode key, Uint16 mod) {
    switch (key) {
    case SDLK_f:
        if (this->showFPS) {
            this->showFPS = false;
            hideFPSCounter();
        } else {
            this->showFPS = true;
            showFPSCounter();
        }
        break;
    }
}

void Game::showFPSCounter() {
    this->fpsCounter = Game::createGameObject();
    this->fpsCounter->addComponent(new components::TextRenderer("[00]", "Mojang", 0.0f));
    this->fpsCounter->setPosition(0, - (this->getRenderingContextHeight() / 2 - 20));

}

void Game::hideFPSCounter() {
    Game::destroyGameObject(fpsCounter);
}

void Game::updateFPSCounter() {
    std::stringstream stream;

    stream << "FPS: " << this->fps;

    ((components::TextRenderer*)this->fpsCounter->getComponent<components::TextRenderer>())->setText(stream.str());
}
