#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "camera.h"
#include "ray.h"
#include "scene.h"
#include "intersection.h"
#include <iostream>
#include <QDebug>

Ray ConstructRayThroughPixel(Camera camera, int x, int y){




    return Ray();
}
Intersection FindIntersection(Ray ray, Scene scene){
    return Intersection();
}

void convertToCameraCoordinates(Scene scene){
    //scene.triangle;
}



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
       ui->setupUi(this);

       int sizeX = 600;
       int sizeY = 600;

       QImage image = QImage(sizeX, sizeY, QImage::Format_RGB32);

       qDebug()  << "Console Mode.\n";
       std::cout << "Console Mode.\n";

       NumberVector camera_xyz_position = NumberVector(0,0,5);
       NumberVector look_at_xyz_position = NumberVector(0,0,0);
       NumberVector up_xyz = NumberVector(0,1,0);

       Camera camera = Camera(camera_xyz_position, look_at_xyz_position, up_xyz);



       Scene scene = Scene();
       convertToCameraCoordinates(scene);

       for(int x=0; x<sizeX; x++){
           for(int y=0; y<sizeY; y++){
               Ray ray = ConstructRayThroughPixel(camera, x, y);
               Intersection hit = FindIntersection(ray, scene);
               image.setPixel(x, y, qRgb(4, 4, 4));
           }

       }

       QGraphicsScene *graphic = new QGraphicsScene(this);

       graphic->addPixmap( QPixmap::fromImage( image ));

       ui->graphicsView->setScene(graphic);
}


MainWindow::~MainWindow()
{
    delete ui;
}
