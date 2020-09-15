#ifndef ROBOT_H
#define ROBOT_H

#include "object.h"
#include <QGraphicsScene>

class Robot : public Object
{
public:
    Robot(qreal x, qreal y, qreal r,qreal speed);
    void advance(int) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget* ) override;
    QPointF firstPoint;
    QPointF lastPoint;

private:
    qreal r;
    bool isMovable = true;
    bool isRotating = false;
    bool reverseMode = false;
    qreal degToRotate = 0;
    double oneStepRotateDeg = 33.0;
    qreal backLen = 0;
    void robotRotate();
    void move(bool reverseMode);
    void robotGoBack();
public:
    QPainterPath shape() const override;
};

#endif // ROBOT_H
