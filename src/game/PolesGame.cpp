#include "PolesGame.h"
#include "scenes/TestScene.h"

PolesGame::PolesGame():
    Game("Poles")
{

}

PolesGame::~PolesGame()
{

}

void PolesGame::start() {
    sceneManager.addScene(new TestScene());
    this->sceneManager.changeScene("Test Scene");
    Game::start();
}
