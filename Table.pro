#-------------------------------------------------
#
# Project created by QtCreator 2016-10-27T19:56:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Table
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cube.cpp \
    scene.cpp \
    observer.cpp \
    leg.cpp \
    toptable.cpp \
    xobject.cpp

HEADERS  += mainwindow.h \
    cube.h \
    scene.h \
    observer.h \
    leg.h \
    toptable.h \
    xobject.h

FORMS    += mainwindow.ui
