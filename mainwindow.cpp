#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "camera.h"
#include "ray.h"
#include "scene.h"
#include "intersection.h"

Ray ConstructRayThroughPixel(Camera camera, int x, int y){
    return Ray();
}
Intersection FindIntersection(Ray ray, Scene scene){
    return Intersection();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
       ui->setupUi(this);

       int sizeX = 600;
       int sizeY = 600;

       QImage image = QImage(sizeX, sizeY, QImage::Format_RGB32);
       Camera camera = Camera();
       Scene scene = Scene();

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
