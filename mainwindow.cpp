#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "camera.h"
#include "ray.h"
#include "scene.h"
#include <iostream>
#include <vector>
#include <QDebug>
#include "object.h"
#include "color.h"
#include "cube.h"

struct intersections_of_scenary{
    int index_of_one_object;
    std::vector<double> intersections_of_one_object;
};

std::vector<Object*> scene_objects;


int winningObjectIndex(std::vector<double> object_intersection){
    //return the index of the winning intersection
    int index_of_minimum_value;

    //prevent unnecessary calculations
    if(object_intersection.size() == 0){
        //if there is no intersections
        return -1;
    }
    else if(object_intersection.size() == 1){
        if(object_intersection.at(0) > 0){
            //if the intersection is greater than zero then its our index of minimum value
            return 0;
        }
        else{
            //otherwise the only intersection value is negative
            return -1;
        }
    }
    else{
        //otherwise there is more than one intersection
        //first find the maximum value

        double max = 0;
        for(int i = 0; i < object_intersection.size() ; i++){
            if(max < object_intersection.at(i)){
                max = object_intersection.at(i);
            }
        }

        //then starting from the maximum value find the minimum positive

        if(max > 0){
            //we only want positive intersections
            for(int index = 0; index < object_intersection.size(); index++){
                if(object_intersection.at(index) > 0 && object_intersection.at(index) <= max){
                    max = object_intersection.at(index);
                    index_of_minimum_value = index;
                }
            }
            return index_of_minimum_value;
        }
        else{
            //all intersections were negative
            return -1;
        }
    }
}

/*
int winningObjectIndex(std::vector<double>  intersections) {
    // para se nao toca em nada
    if (intersections.size() == 0)
        return -1;

    if (intersections.size() == 1) {
        if (intersections.at(0) > 0)
            return 0;
       return -1;
    }

    double min = std::numeric_limits<qlonglong>::max();
    double index = -1;
    for (unsigned int j = 0; j < intersections.size(); j++) {
      if (intersections.at(j) > 0 && intersections.at(j) < min) {
          min = intersections.at(j);
          index = j;
      }
    }

    return index;
}
*/

void createTable(double x, double y, double z){
    Color colorBrown = Color(92.0, 64.0, 51.0, 0);
    Color colorGrey = Color(168.0, 168.0, 168.0, 0);
    double size = 1.0;

    Cube * leg1 = new Cube(size, colorBrown);
    leg1->scale(1.0, 6.0, 1.0);
    leg1->translate(-10.0+x, 9.0+y, 0.0+z);
    scene_objects.push_back(dynamic_cast<Object*>(leg1));

    Cube * leg2 = new Cube(size, colorBrown);
    leg2->scale(1.0, 6.0, 1.0);
    leg2->translate(10.0+x, 9.0+y, 0.0+z);
    scene_objects.push_back(dynamic_cast<Object*>(leg2));

    Cube * leg3 = new Cube(size, colorBrown);
    leg3->scale(1.0, 6.0, 1.0);
    leg3->translate(10.0+x, 9.0+y, 8.0+z);
    scene_objects.push_back(dynamic_cast<Object*>(leg3));

    Cube * leg4 = new Cube(size, colorBrown);
    leg4->scale(1.0, 6.0, 1.0);
    leg4->translate(-10.0+x, 9.0+y, 8.0+z);
    scene_objects.push_back(dynamic_cast<Object*>(leg4));

    Cube * topTable = new Cube(size, colorBrown);
    topTable->scale(14.0, 0.5, 8.0);
    topTable->translate(-1.5+x, 14.5+y, 6.0+z);
    scene_objects.push_back(dynamic_cast<Object*>(topTable));

    Cube * notebookScreen = new Cube(size, colorGrey);
    notebookScreen->scale(4.5, 2.0, 0.5);
    notebookScreen->translate(0.0+x, 17.5+y, 4.0+z);
    scene_objects.push_back(dynamic_cast<Object*>(notebookScreen));

    Cube * notebookKeyboard = new Cube(size, colorGrey);
    notebookKeyboard->scale(4.5, 0.5, 2.0);
    notebookKeyboard->translate(-1.9+x, 14.5+y, -1.4+z);
    scene_objects.push_back(dynamic_cast<Object*>(notebookKeyboard));
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

       ui->setupUi(this);

       int sizeX = 600;
       int sizeY = 600;
       double aspectratio = (double)sizeX / (double)sizeY;
       double xamnt, yamnt;
       QImage image = QImage(sizeX, sizeY, QImage::Format_RGB32);


       //Valores da AP1 de Computação Gráfica
       /*
       NumberVector camera_xyz_position = NumberVector(52, 48, 36);
       NumberVector look_at_xyz_position = NumberVector(3,4,3);
       NumberVector up_xyz = NumberVector(8 - camera_xyz_position.x ,5 - camera_xyz_position.y, 1 - camera_xyz_position.z).normalize();
       */


       //NumberVector camera_xyz_position = NumberVector(-4.25, -2.8, -15);
       //NumberVector camera_xyz_position = NumberVector(-46, 34, 65);

       NumberVector camera_xyz_position = NumberVector(-46, 22, 65);
       NumberVector look_at_xyz_position = NumberVector(0,0,0);
       NumberVector up_xyz = NumberVector(0 , 1, 0);
       Camera camera = Camera(camera_xyz_position, look_at_xyz_position, up_xyz);


       //Scene scene = Scene();

       createTable(0,0,0);
       //createTable(45,0,0);
       //createTable(45,0,-60);
       //createTable(0,0,-60);


       //###This line is important. Here we are changing the coordinates of all vertex of all objects.###
       //camera.transformVertexesFromCoordinatesWorldToCamera(scene_objects);
       //camera.transformVertexesFromCoordinatesCameraToWorld(scene_objects);

       NumberVector origin = camera.camera_xyz_position;
       std::cout<<"camera xyz:"<<camera.camera_xyz_position.x<<" "<<camera.camera_xyz_position.y<<" "<<camera.camera_xyz_position.z<<" \n";



       for(int i=0; i<sizeX; i++){
           for(int j=0; j<sizeY; j++){

               if(sizeX > sizeY){
                    xamnt = ((i+0.5)/sizeX)*aspectratio - (((sizeX - sizeY)/(double)sizeY)/2);
                    yamnt = ((sizeY - j) + 0.5)/sizeY;
               }
               else if(sizeX < sizeY){
                   xamnt = (i + 0.5)/sizeX;
                   yamnt = (((sizeY - j) + 0.5)/sizeY)/aspectratio - (((sizeY - sizeX)/(double)sizeX)/2);
               }
               else{
                   xamnt = (i + 0.5)/sizeX;
                   yamnt = ((sizeY - j) + 0.5)/sizeY;
               }


               //On direction vector we have to use xamnt and yamnt. Both values were calculated before.
               NumberVector direction = camera.camera_look_direction_k.add(camera.camera_right_direction_i.multiply(xamnt - 0.5)
                                                                           .add(camera.camera_down_direction_j.multiply(yamnt - 0.5)))
                                                                           .normalize();


               std::vector<intersections_of_scenary> intersections_of_all_objects;

               for(int index = 0; index < scene_objects.size(); index++){
                   std::vector<double> intersections;
                   std::vector<Triangle*> triangles = scene_objects.at(index)->triangles;
                   for (int x = 0 ; x < triangles.size() ; x++){
                        intersections.push_back(triangles.at(x)->findIntersection(origin, direction));
                   }

                   intersections_of_scenary is;
                   is.index_of_one_object = index;
                   is.intersections_of_one_object.swap(intersections);
                   intersections_of_all_objects.push_back(is);

                   }


               //background color
               image.setPixel(i, j, qRgb(173, 216, 230));


               for(int index = 0; index < scene_objects.size(); index++){
                   int index_of_winning_object = winningObjectIndex(intersections_of_all_objects.at(index).intersections_of_one_object);
                   if(index_of_winning_object != -1){
                       Color this_color = scene_objects.at(index)->triangles.at(index_of_winning_object)->getColor();
                       image.setPixel(i, j, qRgb(this_color.red, this_color.green, this_color.blue));
                   }
               }
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
