#include "paintScene.h"

paintScene::paintScene(QObject *parent) : QGraphicsScene(parent)
{

}
paintScene::~paintScene()
{

}
void paintScene::setLineColor(const QColor &color)
{
    currentColor = color;
    emit lineColorChanged(currentColor);
}
void paintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    addEllipse(event->scenePos().x() - 5,
               event->scenePos().y() - 5,
               10,
               10,
               QPen(Qt::NoPen),
               QBrush(currentColor));
    previousPoint = event->scenePos();
}
void paintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    addLine(previousPoint.x(),
            previousPoint.y(),
            event->scenePos().x(),
            event->scenePos().y(),
            QPen(currentColor,10,Qt::SolidLine,Qt::RoundCap));
    previousPoint = event->scenePos();
}
