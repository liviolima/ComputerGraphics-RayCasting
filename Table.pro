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
    ray.cpp \
    camera.cpp \
    object.cpp \
    triangle.cpp \
    numbervector.cpp \
    cube.cpp \
    material.cpp \
    color.cpp

HEADERS  += mainwindow.h \
    scene.h \
    ray.h \
    camera.h \
    object.h \
    triangle.h \
    numbervector.h \
    cube.h \
    material.h \
    color.h

FORMS    += mainwindow.ui

CONFIG += console
