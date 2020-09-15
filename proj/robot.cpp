#include "myscene.h"
#include "robot.h"
#include <qpainter.h>
#include <QtMath>
#define pi M_PI

Robot::Robot(qreal x, qreal y, qreal r,qreal speed) : Object(x,y,r*2,r*2)
{
    this->r = r;
    this->speed = speed;
    firstPoint = QPointF(0,0);
    lastPoint = firstPoint;
}

//COLLISION DETECTION HERE
void Robot::advance(int)
{
    //qDebug("Deg : %f",degToRotate);
    degToRotate = std::fmod(degToRotate,360);
    if(!isRotating)
        move(false);
    else{
        robotRotate();
    }
}




void Robot::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    //DRAW BOUNDING RECT
    painter->setPen(QColor(0,255,0));
    painter->drawRect(this->boundingRect());


    QColor inColor(0,191,255);
    QColor stickColor(0,0,0);

    QBrush br(inColor);
    painter->setPen(inColor);
    painter->setBrush(br);
    painter->drawEllipse(this->boundingRect());

    painter->setPen(stickColor);
    painter->drawLine(this->boundingRect().center(),this->boundingRect().center()+QPointF(r,0));

    //DRAW ALINAN YOL
}

void Robot::robotRotate()
{
//    qDebug("Robot rotate.");

    int rotateMagnitude = 10;
    this->rotate(oneStepRotateDeg/rotateMagnitude);
    degToRotate-=oneStepRotateDeg/rotateMagnitude;

    if(degToRotate<=0){
        isRotating = false;
        degToRotate = 0;
    }
}

void Robot::move(bool reverseMode)
{
    firstPoint = lastPoint;
//    qDebug("Robot move.");
    float angleRad = rotation() * pi / 180;
    QPointF movePoint(qCos(angleRad)*speed,qSin(angleRad)*speed);

    //FORWARD PATH
    QPainterPath path;
    path.addRect(0,-40,r*1.5,80);
    bool col = detectForwardCollision(path);

    if (!col) {
        if(!reverseMode){
            moveBy(movePoint.x(),movePoint.y());
        }else{
            moveBy(-movePoint.x(),-movePoint.y());
            backLen-= 1;
        }
    }else {
        isRotating = true;
        degToRotate += oneStepRotateDeg;
    }
    lastPoint = this->pos();

//    QPen pen(Qt::red);
//    pen.setWidth(10);
//    ((MyScene)this->scene()).mapPainter->setPen(pen);
//    ((MyScene)this->scene()).mapPainter->drawLine(pos(),pos()+QPointF(10,10));
//    this->scene()->update();

}

void Robot::robotGoBack()
{
    qDebug("Robot go back.");
    move(true);

    if(backLen<=0){
        reverseMode= false;
        backLen = 0;
    }
}

QPainterPath Robot::shape() const
{
    QPainterPath path;
    path.addEllipse(QPointF(0,0),r,r);
    return path;
}


