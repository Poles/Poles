#include "Game.h"
#include <math.h>
#include <Artemis/SystemManager.h>
#include <Artemis/EntityManager.h>
#include <Artemis/Entity.h>
#include "../core/ResourceManager.h"

/* STATIC VARIABLES */
artemis::World Game::world;
artemis::SystemManager * Game::systemManager = world.getSystemManager();
artemis::EntityManager * Game::entityManager = world.getEntityManager();
SDL_Renderer * Game::renderer = NULL;
/*------------------*/


Game::Game() {
    this->run = false;
    
    this->timeLastFrame = 0;
    this->timePerFrame = (Uint32) (((double)1 / (double)FPS_MAX) * 1000);
    this->frameSkip = 0;
    this->fps = 0;
    this->timeLastFPSRecord = SDL_GetTicks();
    
    this->showFPS = false;
    
    /* ARTEMIS */
    this->movementSystem = (MovementSystem *)systemManager->setSystem(new MovementSystem());
    this->renderingSystem = (RenderingSystem *)systemManager->setSystem(new RenderingSystem());
    
    systemManager->initializeAll();
}

Game::~Game() {
    // Free any SDL resource used
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(this->wnd);
    SDL_Quit();
}

void Game::start() {
    this->run = true;
    this->initialize();
    this->mainLoop();
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
    
    /* Testing only */
    int w = mode.w / 2; // Remove / 2 for release
    int h = mode.h / 2;
    
    this->wnd = SDL_CreateWindow(GAME_NAME,
                                 SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                 w,h,
                                 SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(wnd, -1, 0);

    SDL_SetRenderDrawColor(renderer, 25, 25, 25, 255); // Black color for background
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
}

void Game::mainLoop() {
    /* TEST */
    Vector2D position(100,100);
    object = Game::createGameObject();
    object->setPosition(position);
    
    // Load the sprite
    unsigned int animations[1] = {2}; // 1 row with 2 frames
    ResourceManager::loadImage("poles_dude", "/home/ladis/Pictures/poles_dude.png", 1, animations);
    Sprite * sprite = ResourceManager::getSprite("poles_dude");
    sprite->bindAnimation("Static", 0);
    
    // Add the sprite to the objects
    object->addComponent(new SpriteRendererComponent(sprite));
    object->addComponent(new VelocityComponent(0.5f, 0.5f));
    /*------*/
    
    while (this->run) {
        /* ARTEMIS */
        world.loopStart();
        world.setDelta(0.0016f);
        this->movementSystem->process();
        /*---------*/
        
        this->handleEvents();
        this->update();
        
        if (this->frameSkip == 0) {
            this->render();
            this->manageFPS();
        }
        this->countFSP();
    }
}

void Game::update() {
    // With the Artemis-Cpp systems this shouldn't be necessary
}

void Game::render() {
    SDL_RenderClear(renderer);
    
    /* TEST */
    this->renderingSystem->process();
    /*------*/
    SDL_RenderPresent(renderer);
}

void Game::handleEvents() {
    SDL_Event event;
    /* TEST */
    Sprite * sprite = ResourceManager::getSprite("poles_dude");
    Vector2D position(20, 20);
    /*------*/
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_KEYDOWN:
                std::cout << "Key " << SDL_GetKeyName(event.key.keysym.sym) << " Down!" << std::endl;
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        this->run = false;
                        break;
                        
                    case SDLK_f:
                        if (this->showFPS) {
                            this->showFPS = false;
                        } else {
                            this->showFPS = true;
                        }
                        break;
                        /* TEST */
                    case SDLK_1:
                        childObject = Game::createGameObject();
                        childObject->setPosition(position);
                        childObject->setParent(object);
                        childObject->addComponent(new SpriteRendererComponent(sprite));
                        break;
                        
                        
                    case SDLK_2:
                        if (childObject->hasParent()) {
                                childObject->removeParent();
                        } else {
                            childObject->setParent(object);
                        }
                        break;
                        
                        /*-----*/
                        
                    default:
                        break;
                }
                break;
            case SDL_KEYUP:
                
                break;
                
            case SDL_MOUSEMOTION:
                
                break;
                
            case SDL_QUIT:
                this->run = false;
                break;
        }
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
            std::cout << "FPS: " << (int)this->fps << std::endl;
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
    return renderer;
}
