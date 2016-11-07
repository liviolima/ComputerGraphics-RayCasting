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
    leg.cpp \
    toptable.cpp \
    xobject.cpp \
    ray.cpp \
    intersection.cpp \
    camera.cpp

HEADERS  += mainwindow.h \
    scene.h \
    leg.h \
    toptable.h \
    xobject.h \
    ray.h \
    intersection.h \
    camera.h

FORMS    += mainwindow.ui
