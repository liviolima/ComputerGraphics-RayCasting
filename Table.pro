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
    observer.cpp

HEADERS  += mainwindow.h \
    cube.h \
    scene.h \
    observer.h

FORMS    += mainwindow.ui
