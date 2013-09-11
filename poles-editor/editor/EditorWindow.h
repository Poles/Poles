#ifndef EDITORWINDOW_H
#define EDITORWINDOW_H

#include <QMainWindow>
#include "GameRendererWidget.h"

namespace Ui {
class EditorWindow;
}

class EditorWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EditorWindow(QWidget *parent = 0);
    ~EditorWindow();

private slots:
    void on_startStopButton_clicked();

private:
    Ui::EditorWindow * ui;
    GameRendererWidget * gameRendererWidget;
};

#endif // EDITORWINDOW_H
