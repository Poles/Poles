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

    void run();

    void terminate();
};

#endif // GAMETHREAD_H
