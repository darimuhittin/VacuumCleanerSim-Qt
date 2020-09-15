#ifndef OBJECT_H
#define OBJECT_H

#include <QGraphicsEllipseItem>
#include <QPainter>

class Object : public QGraphicsItem
{
public:
    Object(qreal x,qreal y,qreal w,qreal h);
    Object(qreal x,qreal y,qreal w,qreal h,QColor color);
    void rotate(qreal degree);
    bool isMovable = true;
    void setSizeable();
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
    bool detectCollision();
    bool detectForwardCollision(QPainterPath path);
private:
    qreal width;
    qreal height;
    QColor color;
    bool cmdMode=false;
    bool allowMoveWithMouse = false;
    bool allowSizeWithMouse = false;
    QPointF mouseDelta;
    QPointF mouseFirstPoint;
    QPointF mouseLastPoint;
    QPointF mouseOnClickCentralDelta;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    qreal speed;

};

#endif // OBJECT_H
