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

private:
    Ui::GameRendererWidget *ui;
    GameThread gameThread;
};

#endif // GAMERENDERERWIDGET_H
