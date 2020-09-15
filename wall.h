#ifndef WALL_H
#define WALL_H

#include "object.h"

class Wall : public Object
{
public:
    Wall(qreal x, qreal y, qreal w, qreal h);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
private:
    QColor color;
};

#endif // WALL_H
