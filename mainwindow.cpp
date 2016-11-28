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

/*
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
*/

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
       std::cout << "Console Mode.\n";

       NumberVector camera_xyz_position = NumberVector(0, 0, 5);
       NumberVector look_at_xyz_position = NumberVector(0,0,0);
       NumberVector up_xyz = NumberVector(0,1,0);

       Camera camera = Camera(camera_xyz_position, look_at_xyz_position, up_xyz);

       Scene scene = Scene();
       convertToCameraCoordinates(scene);

       Color color = Color(23.0, 124.0, 5.0, 0);
       NumberVector Y = NumberVector(0, 1, 0);
       Plane plane = Plane(Y, -1, color);

       Color color2 = Color(2.0, 20.0, 131.0, 0);
       NumberVector center = NumberVector(0, 0.0, 0.0);
       double radius = 1.0; // ****TRY CHANGE THIS VALUE. JUST ADD 0.1 or SUB 0.1****
       Sphere sphere = Sphere(center, radius, color2);

       Color color3 = Color(255.0, 13.0, 0.0, 0);
       double size = 1.0;
       Cube cube = Cube(size, color3);

       std::vector<Object*> scene_objects;
       //triangle
       //scene_objects.push_back(dynamic_cast<Object*>(&scene.triangle));

       //sphere
       //scene_objects.push_back(dynamic_cast<Object*>(&sphere));

       //cube
       scene_objects.push_back(dynamic_cast<Object*>(&cube));


       //plane
       //scene_objects.push_back(dynamic_cast<Object*>(&plane));




       for(int i=0; i<sizeX; i++){
           for(int j=0; j<sizeY; j++){
               thisone = j*sizeX + i;

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


               NumberVector origin = camera_xyz_position;

               //On direction vector we have to use xamnt and yamnt. Both values were calculated before.
               //NumberVector direction = NumberVector(1, 1, 1); // I need change it]
               NumberVector direction = camera.camera_look_direction_k.add(camera.camera_right_direction_i.multiply(xamnt - 0.5)
                                                                           .add(camera.camera_down_direction_j.multiply(yamnt - 0.5)))
                                                                           .normalize();

               std::vector<double> intersections;
               //intersections.push_back(scene.triangle.findIntersection(origin,direction));


/*
               for(int index = 0; index < scene_objects.size(); index++){
                   intersections.push_back(scene_objects.at(index)->findIntersection(origin,direction));
               }
*/
               std::cout << "Hi-1\n";
               for(int index = 0; index < scene_objects.size(); index++){
                   std::cout << "Hi-2\n";
                   std::vector<Triangle*> triangles = scene_objects.at(index)->triangles;
                   for (int i2 = 0 ; i2 < triangles.size() ; i2++){
                   //for (int i2 = 0 ; i2 < triangles.size()-11 ; i2++){
                            std::cout <<"i: "<<i<<", j: "<<j<<", i2: "<<i2 <<" Hi-3\n";
                            //std::cout << triangles.size();
                            //triangles.at(i2)->printVertexes();
                            double c = triangles.at(i2)->findIntersection(origin, direction);


                            //***************THE ERROR IS ON THE INDEX BELOW ***********
                            //intersections.push_back(triangles[i2].findIntersection(origin, direction));
                            //intersections.push_back(triangles.at(i2)->findIntersection(origin, direction));

                            //**********The problem is here ****************
                            intersections.push_back(c);


                      }
                       //intersections.push_back(scene_objects.at(index)->findIntersection(origin,direction));
               }
               //std::cout <<intersections.at(0)<< "\n";
               std::cout << "Hi-4\n";


               int index_of_winning_object = winningObjectIndex(intersections);
std::cout << "Hi-5\n";
               std::cout <<"index_w: "<<index_of_winning_object << "v  ";
               //qDebug() <<"\n";

               if(index_of_winning_object == -1){
                   //set the background to black
                    image.setPixel(i, j, qRgb(173, 216, 230));
 std::cout << "Hi-6\n";
               }
               else{
                    //index corresponds to an object in our scene.

                   //*************************************
                   //**********PROBLEM IS HERE************
                    //Color this_color = scene_objects.at(index_of_winning_object)->getColor();
                    //Color this_color = Color(255.0, 0.0, 0.0, 0);

                    //Color this_color = scene_objects.at(index_of_winning_object)->getColor();
                    Color this_color = scene_objects.at(0)->triangles.at(index_of_winning_object)->getColor();
                    image.setPixel(i, j, qRgb(this_color.red, this_color.green, this_color.blue));
std::cout << "Hi-7\n";
               }
std::cout << "Hi-8\n";


               /*
               if( (i > 200  && i < 440) && (j > 200) && (j < 280)){
                   image.setPixel(i, j, qRgb(23, 222, 10));
               }
               else{
                   image.setPixel(i, j, qRgb(0, 0, 0));
               }
               */

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
