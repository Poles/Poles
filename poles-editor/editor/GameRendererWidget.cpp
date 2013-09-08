#include "GameRendererWidget.h"
#include "ui_GameRendererWidget.h"

GameRendererWidget::GameRendererWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameRendererWidget)
{
    ui->setupUi(this);
}

GameRendererWidget::~GameRendererWidget()
{
    delete ui;
}
