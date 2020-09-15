#include "mainwindow.h"
#include "object.h"
#include "robot.h"
#include <QKeyEvent>
#include <QMouseEvent>
#include <QRandomGenerator>
#include <QStyle>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    v = new MyView(this);
    this->setWindowTitle("Vacuum Cleaner Simulator");
}
