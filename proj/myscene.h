#ifndef MYSCENE_H
#define MYSCENE_H

#include "robot.h"
#include "wall.h"

#include <QGraphicsScene>
#include <QPushButton>


class MyScene : public QGraphicsScene
{
public:
    MyScene(QObject *parent);
    Robot *robot;
private:
    Wall *wl,*wr,*wu,*wd;
    QPointF getScreenCoor(QPointF coor);
    QPixmap *mapPixmap;
    QPainter *mapPainter;

    // QGraphicsScene interface
protected:
    void drawBackground(QPainter *painter, const QRectF &) override;
    void drawForeground(QPainter *, const QRectF &) override;

    // QGraphicsScene interface
protected:
};

#endif // MYSCENE_H
