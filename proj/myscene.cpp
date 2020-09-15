#include "myscene.h"

#include <QTimer>
#include <QKeyEvent>
#include <QGraphicsView>
MyScene::MyScene(QObject *parent):QGraphicsScene (parent)
{
    robot = new Robot(0,0,10,3);
    addItem(robot);

    qreal wallSize = 600;
    qreal wallThickness = 10;

    wl = new Wall(-wallSize/2,0,wallThickness,wallSize);
    wr = new Wall(wallSize/2,0,wallThickness,wallSize);
    wu = new Wall(0,-wallSize/2,wallSize,wallThickness);
    wd = new Wall(0,wallSize/2,wallSize,wallThickness);

    addItem(wl);
    addItem(wr);
    addItem(wu);
    addItem(wd);

    mapPixmap = new QPixmap(600,600);
    mapPainter = new QPainter(mapPixmap);

    mapPixmap->fill(QColor(0,170,100));

}

void MyScene::drawBackground(QPainter *painter, const QRectF &)
{

    QPen pen(Qt::red);
    QPointF robotToScene(robot->pos().toPoint()+QPoint(300,300));
    pen.setWidth(5);
    mapPainter->setPen(pen);
    mapPainter->drawPoint(robotToScene);
//    qDebug("(%f,%f)",robot->pos().x(),robot->pos().y());
//    qDebug("Robot to scene (%f,%f)",robotToScene.x(),robotToScene.y());
    painter->drawPixmap(QRectF(-300,-300,600,600),*mapPixmap,QRectF(0,0,600,600));
    update();
}

void MyScene::drawForeground(QPainter *, const QRectF &)
{

}



