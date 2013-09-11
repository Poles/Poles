#include "GameRendererWidget.h"
#include "ui_GameRendererWidget.h"

GameRendererWidget::GameRendererWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameRendererWidget) {
    ui->setupUi(this);

    // Connect the signal and slots for receiving the pixels of the frame
    connect(& gameThread,
            SIGNAL(frameReady(unsigned char*,int,int)),
            this,
            SLOT(receiveFrame(unsigned char*,int,int)));
}

GameRendererWidget::~GameRendererWidget() {
    delete ui;
}

void GameRendererWidget::startGame() {
    this->gameThread.start();
}

void GameRendererWidget::receiveFrame(unsigned char * pixels, int width, int height) {
    if (currentFrame != NULL) {
        delete currentFrame;
    }

    currentFrame = new QImage(pixels, width, height, QImage::Format_ARGB32);

    QPixmap  pixmap;
    pixmap.convertFromImage(* currentFrame);
    //pixmap = pixmap.scaled(ui->rendererFrame->width(), ui->rendererFrame->height());
    ui->rendererFrame->clear();
    ui->rendererFrame->setPixmap(pixmap);
}
