#include "myview.h"
#include "wall.h"

#include <QTimer>
#include <QKeyEvent>
#include <QRandomGenerator>
#include <QGraphicsSceneEvent>
MyView::MyView(QWidget *parent) : QGraphicsView (parent)
{
    timer = new QTimer();
    btnAddItem = new QPushButton("Add Item",this);
    btnIncSpeed = new QPushButton("Fast",this);
    btnDecSpeed = new QPushButton("Slow",this);
    s = new MyScene(this);


    setScene(s);
    setFixedSize(850,650);
    setAlignment(Qt::AlignHCenter);


    btnDecSpeed->move(0,60);
    btnAddItem->move(0,0);
    btnIncSpeed->move(0,30);
    QObject::connect(btnAddItem,SIGNAL(clicked()),this,SLOT(addNewRectToScene()));
    QObject::connect(btnIncSpeed,SIGNAL(clicked()),this,SLOT(incTimerSpeed()));
    QObject::connect(btnDecSpeed,SIGNAL(clicked()),this,SLOT(decTimerSpeed()));
    QObject::connect(timer, &QTimer::timeout, s, &QGraphicsScene::advance);

    //timer->start(1000 / fps);
    timer->start(1);

    header = new QGraphicsTextItem("Vacuum Cleaner Simulator");
    header->setFont(QFont("Comic Sans",30,50,false));
    header->moveBy(-250,-350);
    s->addItem(header);


}

void MyView::incTimerSpeed()
{
//    if(fps<=100000000){
//        fps *= 10;
//        timer->start(qreal(1000.0/fps));
//    }
    fps = 1000;
    timer->start(qreal(1000/fps));
}

void MyView::decTimerSpeed()
{
//    if(fps>=100){
//        fps /= 10;
//        timer->start(qreal(1000.0/fps));
//    }
    fps = 60;
    timer->start(qreal(1000/fps));
}

void MyView::addNewRectToScene(){
    QColor color(QRandomGenerator::global()->bounded(256),
                 QRandomGenerator::global()->bounded(256),
                 QRandomGenerator::global()->bounded(256));
    s->addItem(new Object(0,0,50,50,color));
}






void MyView::wheelEvent(QWheelEvent *event)
{
    if(event->angleDelta().y()>0)
        scale(1.1,1.1);
    else {
        scale(0.9,0.9);
    }
}
