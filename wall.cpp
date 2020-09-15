#include "wall.h"



Wall::Wall(qreal x, qreal y, qreal w, qreal h):Object(x,y,w,h)
{
    color = QColor(150,0,0);
}

void Wall::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(this->color);
    painter->setBrush(color);
    painter->drawRect(boundingRect());
}
