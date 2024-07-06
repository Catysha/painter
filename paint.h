#ifndef PAINT_H
#define PAINT_H

#include <QWidget>
#include <QTimer>
#include <QResizeEvent>
#include <QPushButton>
#include <QPainter>
#include <QColorDialog>
#include <paintScene.h>

namespace Ui {
class Paint;
}

class Paint : public QWidget
{
    Q_OBJECT

public:
    explicit Paint(QWidget *parent = 0);
    ~Paint();
private slots:
    void slotTimer();
    void setRedColor();
    void setOrangeColor();
    void setYellowColor();
    void setGreenColor();
    void setLightBlueColor();
    void setBlueColor();
    void setPurpleColor();
    void setBrownColor();
    void setBlackColor();
    void setRubber();
private:
    Ui::Paint *ui;
    QTimer *timer;
    paintScene *scene;
    void resizeEvent(QResizeEvent * event);
    QPushButton *buttonRed;
    QPushButton *buttonOrange;
    QPushButton *buttonYellow;
    QPushButton *buttonGreen;
    QPushButton *buttonLightBlue;
    QPushButton *buttonBlack;
    QPushButton *buttonBrown;
    QPushButton *buttonPurple;
    QPushButton *buttonBlue;
    QPushButton *buttonRubber;

};

#endif // PAINT_H
