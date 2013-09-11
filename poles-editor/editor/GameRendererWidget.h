#ifndef GAMERENDERERWIDGET_H
#define GAMERENDERERWIDGET_H

#include <QWidget>
#include "GameThread.h"

namespace Ui {
class GameRendererWidget;
}

class GameRendererWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameRendererWidget(QWidget *parent = 0);
    ~GameRendererWidget();

    void startGame();

public slots:
    void receiveFrame(unsigned char * pixels, int width, int height);

private:
    Ui::GameRendererWidget *ui;
    GameThread gameThread;
    QImage * currentFrame;
};

#endif // GAMERENDERERWIDGET_H
