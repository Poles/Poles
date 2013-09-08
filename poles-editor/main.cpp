#include <QApplication>
#include "../src/game/Game.h"
#include "../src/core/ResourceManager.h"

#undef main     // Fixs a problem between the SDL2 main and the Qt main

int main(int argc, char *argv[])
{
    ResourceManager::initialize();

//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    return a.exec();

    Game * game = new Game();
    game->start();

    return 0;
}
