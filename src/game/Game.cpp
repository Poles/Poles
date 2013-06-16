#include "Game.h"

Game::Game() {
    this->run = false;
    
    this->timeLastFrame = 0;
    this->timePerFrame = (Uint32) (((double)1 / (double)FPS_MAX) * 1000);
    this->frameSkip = 0;
    this->fps = 0;
    this->timeLastFPSRecord = SDL_GetTicks();
    
    this->showFPS = false;
    
    /* TEST */
    this->circle = new Circle(0,250, 10);
    this->circle->setColor(Color(255,0,255,255));
}

Game::~Game() {
    // Free any SDL resource used
    SDL_DestroyRenderer(this->rc);
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
    rc = SDL_CreateRenderer(wnd, -1, 0);
    
    SDL_SetRenderDrawColor(rc, 60, 60, 60, 255); // Black color for background
}

void Game::mainLoop() {
    while (this->run) {
        
        this->handleEvents();
        this->update();
        
        if (this->frameSkip == 0) {
            this->render();
            this->manageFPS();
            this->countFSP();
        }
    }
}

void Game::update() {
    /* TESTING */
    this->circle->setPosition((int)(circle->position().x() + 1) % 300 , circle->position().y());
}

void Game::render() {
    SDL_RenderPresent(this->rc);
    SDL_RenderClear(this->rc);
    
    
    /* Rendering code here */
    this->circle->draw(this->rc);    
}

void Game::handleEvents() {
    SDL_Event event;
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
