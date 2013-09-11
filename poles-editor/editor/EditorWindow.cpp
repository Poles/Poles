#include "EditorWindow.h"
#include "ui_EditorWindow.h"

EditorWindow::EditorWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EditorWindow) {
    ui->setupUi(this);

    // Add the renderer widget to the window
    this->gameRendererWidget = new GameRendererWidget(this);
    ui->rendererLayout->addWidget(this->gameRendererWidget);
}

EditorWindow::~EditorWindow() {
    delete ui;
}

void EditorWindow::on_startStopButton_clicked() {
    this->gameRendererWidget->startGame();
}
