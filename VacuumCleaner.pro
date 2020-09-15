TEMPLATE = app
TARGET = VacuumCleaner

QT += core gui

greaterThan(QT_MAJOR_VERSION,4): QT += widgets

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    object.cpp \
    robot.cpp \
    wall.cpp \
    myscene.cpp \
    myview.cpp

HEADERS += \
    mainwindow.h \
    object.h \
    robot.h \
    wall.h \
    myscene.h \
    myview.h
