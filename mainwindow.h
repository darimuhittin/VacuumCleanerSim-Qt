#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "myscene.h"
#include "myview.h"
#include "object.h"
#include "robot.h"

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMainWindow>
#include <QPushButton>
#include <QTimer>

class MainWindow : public QMainWindow
{
public:
    explicit MainWindow(QWidget *parent = nullptr);
    MyView *v;
};

#endif // MAINWINDOW_H
