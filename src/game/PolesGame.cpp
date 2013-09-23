#include "PolesGame.h"
#include "scenes/TestScene.h"

PolesGame::PolesGame():
    Game("Poles")
{
    sceneManager.addScene(new TestScene());
    sceneManager.changeScene("Test Scene");
}

PolesGame::~PolesGame()
{

}
