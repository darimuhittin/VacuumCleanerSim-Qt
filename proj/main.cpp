#include <QApplication>
#include <QGraphicsView>
#include <QGuiApplication>
#include <QImage>
#include <QPainter>
#include <QPicture>
#include <QPushButton>
#include <QTimer>
#include <QWindow>

#include <QStyle>
#include <QDesktopWidget>
#include "mainwindow.h"
#include "robot.h"
#include "wall.h"
int main(int argc, char *argv[])
{

    QApplication app(argc,argv);
    qputenv("QT_DEVICE_PIXEL_RATIO", "0");
    qputenv("QT_AUTO_SCREEN_SCALE_FACTOR", "1");
    MainWindow wnd;
    wnd.setFixedSize(850,650);


//    wnd.setFixedSize(1000,800);
//    Robot *r2 = new Robot(100,0,50,0.1);
//    Robot *r3 = new Robot(0,100,50,0.1);
//    Robot *r4 = new Robot(100,100,50,0.1);

    wnd.show();
    return app.exec();
}

void degis(){

}
