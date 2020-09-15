#include "object.h"
#include "QtMath"
#include <QDebug>
#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>


#define pi 3.14159265359

Object::Object(qreal x, qreal y, qreal w, qreal h)
{
    width = w;
    height = h;
    speed = 0.1;
    setPos(x,y);
    color = QColor(0,0,0);

}

Object::Object(qreal x, qreal y, qreal w, qreal h, QColor color) : Object(x,y,w,h)
{
    this->color = color;
}


//Degree + for clockwise
void Object::rotate(qreal degree){
    setRotation(rotation()+degree);
}

bool Object::detectCollision()
{
    QPainterPath path(shape()); //NORMAL
    const QList<QGraphicsItem*> obs = scene()-> items(mapToScene(path));
    return (obs.size()>1 ? true : false);
}


bool Object::detectForwardCollision(QPainterPath path)
{
    const QList<QGraphicsItem*> obs = scene()-> items(mapToScene(path));

    if(obs.size()>1){
        return true;
    }
    else
    {
        return false;
    }
}

QRectF Object::boundingRect() const
{
    return QRectF(-width/2,-height/2,width,height);
}

QPainterPath Object::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void Object::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(color);
    painter->setBrush(color);
    painter->drawRect(boundingRect());

}







void Object::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug("Mouse press");
    switch (event->button()) {
    case Qt::LeftButton:
        allowMoveWithMouse = true;
        break;
    case Qt::RightButton:
        allowSizeWithMouse = true;
        break;
    default:
        break;
    }
    mouseFirstPoint = mapToScene(event->pos());
    mouseOnClickCentralDelta = mapToScene(event->pos()) - pos();
}

void Object::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    mouseLastPoint = mapToScene(event->pos());
    mouseDelta = mouseLastPoint - mouseFirstPoint;
    //qreal delx = mouseDelta.x();
    qreal dely = mouseDelta.y();
    qreal scalingFactor = 0.01;

    //qreal deltxfac =delx * scalingFactor;
    qreal deltyfac =dely * scalingFactor *-1;

    //qDebug("Mouse delta : %f",mouseDelta);
    if (allowMoveWithMouse){
        setPos(mapToScene(event->pos())-mouseOnClickCentralDelta);
    }
    else if(allowSizeWithMouse){
        if(this->scale()+deltyfac > 0 && deltyfac< 5){
            setScale(scale()+deltyfac);
        }
    }
    mouseFirstPoint = mouseLastPoint;
}

void Object::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

    qDebug("Mouse release");
    switch (event->button()) {
    case Qt::LeftButton:
        allowMoveWithMouse = false;
        break;
    case Qt::RightButton:
        allowSizeWithMouse = false;
        break;
    default:
        break;
    }
}


void Object::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Control)
        cmdMode = true;
}

void Object::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Control)
        cmdMode = false;
}
