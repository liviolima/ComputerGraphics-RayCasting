#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "camera.h"
#include "ray.h"
#include "scene.h"
#include <iostream>
#include <vector>
#include <QDebug>
#include "object.h"
#include "plane.h"
#include "color.h"
#include "sphere.h"
#include "cube.h"

struct intersections_of_scenary{
    int index_of_one_object;
    std::vector<double> intersections_of_one_object;
};


void convertToCameraCoordinates(Scene scene){
    //I did it on the class Camera.
}

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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

       ui->setupUi(this);

       int thisone;
       int sizeX = 600;
       int sizeY = 600;
       double aspectratio = (double)sizeX / (double)sizeY;
       double xamnt, yamnt;
       QImage image = QImage(sizeX, sizeY, QImage::Format_RGB32);

       qDebug()  << "Console Mode.\n";




       //NumberVector camera_xyz_position = NumberVector(0, 0, 5);
       //Valores da prova
       //NumberVector camera_xyz_position = NumberVector(52, 48, 36);
       //NumberVector look_at_xyz_position = NumberVector(3,4,3);
       //NumberVector up_xyz = NumberVector(8 - camera_xyz_position.x ,5 - camera_xyz_position.y, 1 - camera_xyz_position.z).normalize();


       //NumberVector camera_xyz_position = NumberVector(-4.25, -2.8, -15);
       //NumberVector camera_xyz_position = NumberVector(-46, 34, 65);
       NumberVector camera_xyz_position = NumberVector(-46, 22, 65);

       NumberVector look_at_xyz_position = NumberVector(0,0,0);
       NumberVector up_xyz = NumberVector(0 , 1, 0);


       Camera camera = Camera(camera_xyz_position, look_at_xyz_position, up_xyz);
       Scene scene = Scene();
       convertToCameraCoordinates(scene);
       std::vector<Object*> scene_objects;


       //Triangle
       //scene_objects.push_back(dynamic_cast<Object*>(&scene.triangle));

       //Plane
/*
       Color color = Color(233.0, 24.0, 25.0, 0);
       NumberVector Y = NumberVector(0, 1, 0);
       Plane plane = Plane(Y, -1, color);
       scene_objects.push_back(dynamic_cast<Object*>(&plane));
*/

       //Sphere
/*
       Color color2 = Color(2.0, 20.0, 131.0, 0);
       NumberVector center = NumberVector(0, 1.0, 0.0);
       double radius = 1.2; // ****TRY CHANGE THIS VALUE. JUST ADD 0.1 or SUB 0.1****
       Sphere sphere = Sphere(center, radius, color2);
       scene_objects.push_back(dynamic_cast<Object*>(&sphere));
*/

       //Cube
       Color color3 = Color(255.0, 13.0, 0.0, 0);
       double size = 1.0;

       Cube leg1 = Cube(size, color3);
       leg1.scale(1.0, 6.0, 1.0);
       leg1.translate(-10.0, 9.0, 0.0);
       scene_objects.push_back(dynamic_cast<Object*>(&leg1));

       Cube leg2 = Cube(size, color3);
       leg2.scale(1.0, 6.0, 1.0);
       leg2.translate(10.0, 9.0, 0.0);
       scene_objects.push_back(dynamic_cast<Object*>(&leg2));

       Cube leg3 = Cube(size, color3);
       leg3.scale(1.0, 6.0, 1.0);
       leg3.translate(10.0, 9.0, 8.0);
       scene_objects.push_back(dynamic_cast<Object*>(&leg3));

       Cube leg4 = Cube(size, color3);
       leg4.scale(1.0, 6.0, 1.0);
       leg4.translate(-10.0, 9.0, 8.0);
       scene_objects.push_back(dynamic_cast<Object*>(&leg4));

       Cube topTable = Cube(size, color3);
       topTable.scale(14.0, 0.5, 8.0);
       topTable.translate(-1.5, 14.5, 6.0);
       scene_objects.push_back(dynamic_cast<Object*>(&topTable));

       Cube notebookScreen = Cube(size, color3);
       notebookScreen.scale(4.5, 2.0, 0.5);
       notebookScreen.translate(0.0, 17.5, 4.0);
       scene_objects.push_back(dynamic_cast<Object*>(&notebookScreen));

       Cube notebookKeyboard = Cube(size, color3);
       notebookKeyboard.scale(4.5, 0.5, 2.0);
       notebookKeyboard.translate(-1.9, 14.5, -1.4);
       scene_objects.push_back(dynamic_cast<Object*>(&notebookKeyboard));





       //###This line is important. Here we are changing the coordinates of all vertex of all objects.###
       //camera.transformVertexesFromCoordinatesWorldToCamera(scene_objects);
       //camera.transformVertexesFromCoordinatesCameraToWorld(scene_objects);

       NumberVector origin = camera.camera_xyz_position;
       std::cout<<"camera xyz:"<<camera.camera_xyz_position.x<<" "<<camera.camera_xyz_position.y<<" "<<camera.camera_xyz_position.z<<" \n";
       //NumberVector origin = NumberVector(0,0,0);



       for(int i=0; i<sizeX; i++){
           for(int j=0; j<sizeY; j++){
               //thisone = j*sizeX + i;

               if(sizeX > sizeY){
                    xamnt = ((i+0.5)/sizeX)*aspectratio - (((sizeX - sizeY)/(double)sizeY)/2);
                    yamnt = ((sizeY - j) + 0.5)/sizeY;
               }
               else if(sizeX < sizeY){
                   xamnt = (i + 0.5)/sizeX;
                   yamnt = (((sizeY - j) + 0.5)/sizeY)/aspectratio - (((sizeY - sizeX)/(double)sizeX)/2);
               }
               else{
                   //the image is a square
                   xamnt = (i + 0.5)/sizeX;
                   yamnt = ((sizeY - j) + 0.5)/sizeY;
               }



              //std::cout<<xamnt<<" "<<yamnt<<" \n";




               //On direction vector we have to use xamnt and yamnt. Both values were calculated before.
               NumberVector direction = camera.camera_look_direction_k.add(camera.camera_right_direction_i.multiply(xamnt - 0.5)
                                                                           .add(camera.camera_down_direction_j.multiply(yamnt - 0.5)))
                                                                           .normalize();




               //std::cout<<direction.x<<" "<<direction.y<<" "<<direction.z<<" \n";



               //We used this before
/*
               for(int index = 0; index < scene_objects.size(); index++){
                   intersections.push_back(scene_objects.at(index)->findIntersection(origin,direction));
               }
*/


               std::vector<intersections_of_scenary> intersections_of_all_objects;


               for(int index = 0; index < scene_objects.size(); index++){
                   std::vector<double> intersections;
                   std::vector<Triangle*> triangles = scene_objects.at(index)->triangles;
                   for (int x = 0 ; x < triangles.size() ; x++){
                            //std::cout <<"i: "<<i<<", j: "<<j<<", i2: "<<i2 <<" Hi-3\n";
                            //std::cout << triangles.size();
                            //triangles.at(i2)->printVertexes();

                              // is = { index, intersections_of_one_objects.push_back(triangles.at(x)->findIntersection(origin, direction));
                             // };



                       intersections.push_back(triangles.at(x)->findIntersection(origin, direction));


                   }

                   intersections_of_scenary is;
                   is.index_of_one_object = index;
                   is.intersections_of_one_object.swap(intersections);
                   intersections_of_all_objects.push_back(is);
//}

                   }
               for(int index = 0; index < scene_objects.size(); index++){
                   image.setPixel(i, j, qRgb(173, 216, 230));
               }


               for(int index = 0; index < scene_objects.size(); index++){


                    int index_of_winning_object = winningObjectIndex(intersections_of_all_objects.at(index).intersections_of_one_object);

    //std::cout << index_of_winning_object; //Test to see intersections (-1 or 1 or 0 values)

                   if(index_of_winning_object == -1){
                       //set the background to this color
                       //image.setPixel(i, j, qRgb(173, 216, 230));
                   }
                   else{
                        //index corresponds to an object in our scene.
                        //Color this_color = scene_objects.at(index_of_winning_object)->getColor();
                        //Color this_color = Color(255.0, 0.0, 0.0, 0);
    //                   for(int index = 0; i < scene_objects.size(); index++){
                         Color this_color = scene_objects.at(index)->triangles.at(index_of_winning_object)->getColor();
                         image.setPixel(i, j, qRgb(this_color.red, this_color.green, this_color.blue));


                   }
               }

//std::cout<<"test 5 \n";

//std::cout<<"test 7 \n";
               //------------This is just a test-------------
               /*
               if( (i > 200  && i < 440) && (j > 200) && (j < 280)){
                   image.setPixel(i, j, qRgb(23, 222, 10));
               }
               else{
                   image.setPixel(i, j, qRgb(0, 0, 0));
               }
               */
               //------------This is a pseudo-code------------
               /*
               Ray ray = ConstructRayThroughPixel(camera, i, j);
               Intersection hit = FindIntersection(ray, scene);
               image.setPixel(i, j, qRgb(4, 4, 4));]
               */
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
