#ifndef GAMETHREAD_H
#define GAMETHREAD_H

#include <QThread>
#include "../../src/game/Game.h"

class GameThread : public QThread, public Game
{
    Q_OBJECT
public:
    GameThread();
    virtual ~GameThread();

    void start();

    void initialize();

    void run();

    void terminate();

signals:
    void frameReady(unsigned char * pixels, int width, int height);

private:
    bool running;
    static SDL_Surface * rendererSurface;
};

#endif // GAMETHREAD_H
