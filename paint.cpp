#include "paint.h"
#include "ui_paint.h"

Paint::Paint(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Paint)
{
    ui->setupUi(this);

    scene = new paintScene();
    ui->graphicsView->setScene(scene);

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &Paint::slotTimer);
    timer->start(100);
    buttonRed = ui->redButton;
    buttonOrange = ui->orangeButton;
    buttonYellow = ui->yellowButton;
    buttonGreen = ui->greenButton;
    buttonLightBlue = ui->lightBlueButton;
    buttonBlue = ui->blueButton;
    buttonPurple = ui->purpleButton;
    buttonBrown = ui->brownButton;
    buttonBlack = ui->blackButton;
    buttonRubber = ui->rubberButton;

    connect(buttonRed, &QPushButton::clicked, this, &Paint::setRedColor);
    connect(buttonOrange, &QPushButton::clicked, this, &Paint::setOrangeColor);
    connect(buttonYellow, &QPushButton::clicked, this, &Paint::setYellowColor);
    connect(buttonGreen, &QPushButton::clicked, this, &Paint::setGreenColor);
    connect(buttonLightBlue, &QPushButton::clicked, this, &Paint::setLightBlueColor);
    connect(buttonBlue, &QPushButton::clicked, this, &Paint::setBlueColor);
    connect(buttonPurple, &QPushButton::clicked, this, &Paint::setPurpleColor);
    connect(buttonBrown, &QPushButton::clicked, this, &Paint::setBrownColor);
    connect(buttonBlack, &QPushButton::clicked, this, &Paint::setBlackColor);
    connect(buttonRubber, &QPushButton::clicked, this, &Paint::setRubber);
}

Paint::~Paint()
{
    delete ui;
}

void Paint::slotTimer()
{

    timer->stop();
    scene->setSceneRect(0,0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
}

void Paint::resizeEvent(QResizeEvent *event)
{
    timer->start(100);
    QWidget::resizeEvent(event);
}
void Paint::setRedColor()
{
    scene->setLineColor(Qt::red);
}
void Paint::setOrangeColor()
{
    QColor orangeColor(255, 165, 0);
    scene->setLineColor(orangeColor);
}
void Paint::setYellowColor()
{
    scene->setLineColor(Qt::yellow);
}
void Paint::setGreenColor()
{
    scene->setLineColor(Qt::green);
}
void Paint::setLightBlueColor()
{
    QColor lightBlueColor(173, 216, 230);
    scene->setLineColor(lightBlueColor);
}
void Paint::setBlueColor()
{
    scene->setLineColor(Qt::blue);
}
void Paint::setPurpleColor()
{
    QColor purpleColor(128, 0, 128);
    scene->setLineColor(purpleColor);
}
void Paint::setBrownColor()
{
    QColor brownColor(139, 69, 19);
    scene->setLineColor(brownColor);
}
void Paint::setBlackColor()
{
    scene->setLineColor(Qt::black);
}
void Paint::setRubber()
{
    scene->setLineColor(Qt::white);
}
