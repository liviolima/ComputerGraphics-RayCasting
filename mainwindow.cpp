#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "camera.h"
#include "ray.h"
#include "scene.h"
#include "intersection.h"
#include <iostream>
#include <QDebug>

Ray ConstructRayThroughPixel(Camera camera, int i, int j){

    //I have to change the correct values for Pz, Dx, Dy.

    double Px, Py, Pz = -10.0;
    double Dx = 1.0, Dy = 1.0;
    double W = 10, H = 10;

    Px = W/2.0 +  Dx/2.0 + j*Dx;
    Py = H/2.0 - Dy/2.0 - i*Dy;


    NumberVector P(Px, Py, Pz);

    Ray ray;
    ray.calculateV(P);


    return ray;
}

Intersection FindIntersection(Ray ray, Scene scene){
    return Intersection();
}

void convertToCameraCoordinates(Scene scene){

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

       for(int i=0; i<sizeX; i++){
           for(int j=0; j<sizeY; j++){
               Ray ray = ConstructRayThroughPixel(camera, i, j);
               Intersection hit = FindIntersection(ray, scene);
               image.setPixel(i, j, qRgb(4, 4, 4));
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
