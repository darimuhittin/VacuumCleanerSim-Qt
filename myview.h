#ifndef MYVIEW_H
#define MYVIEW_H

#include "myscene.h"
#include "wall.h"

#include <QGraphicsView>



class MyView : public QGraphicsView
{
    Q_OBJECT
public:
    MyView(QWidget *parent);
    MyScene *s;
    void addItemToScene(QGraphicsItem *itemToAdd);
private:
    qreal fps = 60;
    QPushButton *btnAddItem;
    QPushButton *btnIncSpeed;
    QPushButton *btnDecSpeed;
    QTimer *timer;
    QGraphicsTextItem *header;

public slots:
    void addNewRectToScene();
    void incTimerSpeed();
    void decTimerSpeed();

    // QGraphicsView interface
protected:

    // QWidget interface
protected:
    void wheelEvent(QWheelEvent *event) override;
};

#endif // MYVIEW_H
