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
    scene.cpp \
    leg.cpp \
    toptable.cpp \
    xobject.cpp \
    ray.cpp \
    intersection.cpp \
    camera.cpp \
    object.cpp \
    triangle.cpp \
    numbervector.cpp

HEADERS  += mainwindow.h \
    scene.h \
    leg.h \
    toptable.h \
    xobject.h \
    ray.h \
    intersection.h \
    camera.h \
    object.h \
    triangle.h \
    numbervector.h

FORMS    += mainwindow.ui
