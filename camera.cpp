#include "camera.h"
#include <iostream>
#include <QDebug>
#include "triangle.h"
#include "scene.h"
#include "object.h"

Camera::Camera()
{

    //deve possuir as posicoes do observador.
    //Para onde ele esta olhando


}

Camera::Camera(NumberVector pos, NumberVector look_at, NumberVector up){
    this->camera_xyz_position = pos;
    this->look_at_xyz_position = look_at;
    this->up_xyz = up;


    this->camera_look_direction_k = NumberVector(
                this->camera_xyz_position.x - this->look_at_xyz_position.x,
                this->camera_xyz_position.y - this->look_at_xyz_position.y,
                this->camera_xyz_position.z - this->look_at_xyz_position.z)
            .negative().normalize();

    this->camera_right_direction_i = up_xyz.cross_product(camera_look_direction_k).normalize();
    this->camera_down_direction_j = camera_right_direction_i.cross_product(camera_look_direction_k);



    double Oc_i1 = camera_xyz_position.dot_product(camera_right_direction_i);
    double Oc_j1 = camera_xyz_position.dot_product(camera_down_direction_j);
    double Oc_k1 = camera_xyz_position.dot_product(camera_look_direction_k);



//-------- World To Camera Matrix ---------
    coordinatesWorldToCamera[0][0] = camera_right_direction_i.x;
    coordinatesWorldToCamera[1][0] = camera_down_direction_j.x;
    coordinatesWorldToCamera[2][0] = camera_look_direction_k.x;
    coordinatesWorldToCamera[3][0] = 0.0;

    coordinatesWorldToCamera[0][1] = camera_right_direction_i.y;
    coordinatesWorldToCamera[1][1] = camera_down_direction_j.y;
    coordinatesWorldToCamera[2][1] = camera_look_direction_k.y;
    coordinatesWorldToCamera[3][1] = 0.0;

    coordinatesWorldToCamera[0][2] = camera_right_direction_i.z;
    coordinatesWorldToCamera[1][2] = camera_down_direction_j.z;
    coordinatesWorldToCamera[2][2] = camera_look_direction_k.z;
    coordinatesWorldToCamera[3][2] = 0.0;

    coordinatesWorldToCamera[0][3] = -Oc_i1;
    coordinatesWorldToCamera[1][3] = -Oc_j1;
    coordinatesWorldToCamera[2][3] = -Oc_k1;
    coordinatesWorldToCamera[3][3] = 1.0;

    qDebug() <<"World to Camera Matrix\n";
    for(int j = 0; j < 4; j++){
       qDebug() <<coordinatesWorldToCamera[j][0]<<" "<<coordinatesWorldToCamera[j][1]<<" "<<coordinatesWorldToCamera[j][2]<<" "<<coordinatesWorldToCamera[j][3];
       qDebug() <<"\n";
    }



//-------- Camera To World Matrix ---------
    coordinatesCameraToWorld[0][0] = camera_right_direction_i.x;
    coordinatesCameraToWorld[1][0] = camera_right_direction_i.y;
    coordinatesCameraToWorld[2][0] = camera_right_direction_i.z;
    coordinatesCameraToWorld[3][0] = 0.0;

    coordinatesCameraToWorld[0][1] = camera_down_direction_j.x;
    coordinatesCameraToWorld[1][1] = camera_down_direction_j.y;
    coordinatesCameraToWorld[2][1] = camera_down_direction_j.z;
    coordinatesCameraToWorld[3][1] = 0.0;

    coordinatesCameraToWorld[0][2] = camera_look_direction_k.z;
    coordinatesCameraToWorld[1][2] = camera_look_direction_k.z;
    coordinatesCameraToWorld[2][2] = camera_look_direction_k.z;
    coordinatesCameraToWorld[3][2] = 0.0;

    coordinatesCameraToWorld[0][3] = camera_xyz_position.x;
    coordinatesCameraToWorld[1][3] = camera_xyz_position.y;
    coordinatesCameraToWorld[2][3] = camera_xyz_position.z;
    coordinatesCameraToWorld[3][3] = 1.0;

    qDebug() <<"Camera to World Matrix\n";
    for(int j = 0; j < 4; j++){
        qDebug() <<coordinatesCameraToWorld[j][0]<<" "<<coordinatesCameraToWorld[j][1]<<" "<<coordinatesCameraToWorld[j][2]<<" "<<coordinatesCameraToWorld[j][3];
        qDebug() <<"\n";
    }


}


void Camera::transformVertexesFromCoordinatesWorldToCamera(std::vector<Object*> scene_objects){

     for(int index = 0; index < scene_objects.size(); index++){

         std::vector<Triangle*> triangles = scene_objects.at(index)->triangles;
         for (int i = 0 ; i < triangles.size() ; i++){
                 std::cout<<"\nTriangle["<<i<<"]\n";
                 std::cout<<"before transformation\n";
                 triangles.at(i)->printVertexes();


                 //----------vertex[0] of this triangle------------

                  triangles.at(i)->vertex[0].x =   coordinatesWorldToCamera[0][0] * triangles.at(i)->vertex[0].x +
                                                   coordinatesWorldToCamera[0][1] * triangles.at(i)->vertex[0].y +
                                                   coordinatesWorldToCamera[0][2] * triangles.at(i)->vertex[0].z +
                                                   coordinatesWorldToCamera[0][3] * 1;


                  triangles.at(i)->vertex[0].y =    coordinatesWorldToCamera[1][0] * triangles.at(i)->vertex[0].x +
                                                    coordinatesWorldToCamera[1][1] * triangles.at(i)->vertex[0].y +
                                                    coordinatesWorldToCamera[1][2] * triangles.at(i)->vertex[0].z +
                                                    coordinatesWorldToCamera[1][3] * 1;


                  triangles.at(i)->vertex[0].z =   coordinatesWorldToCamera[2][0] * triangles.at(i)->vertex[0].x +
                                                   coordinatesWorldToCamera[2][1] * triangles.at(i)->vertex[0].y +
                                                   coordinatesWorldToCamera[2][2] * triangles.at(i)->vertex[0].z +
                                                   coordinatesWorldToCamera[2][3] * 1;



                  //----------vertex[1] of this triangle------------
                  triangles.at(i)->vertex[1].x =   coordinatesWorldToCamera[0][0] * triangles.at(i)->vertex[1].x +
                                                   coordinatesWorldToCamera[0][1] * triangles.at(i)->vertex[1].y +
                                                   coordinatesWorldToCamera[0][2] * triangles.at(i)->vertex[1].z +
                                                   coordinatesWorldToCamera[0][3] * 1;


                  triangles.at(i)->vertex[1].y =    coordinatesWorldToCamera[1][0] * triangles.at(i)->vertex[1].x +
                                                    coordinatesWorldToCamera[1][1] * triangles.at(i)->vertex[1].y +
                                                    coordinatesWorldToCamera[1][2] * triangles.at(i)->vertex[1].z +
                                                    coordinatesWorldToCamera[1][3] * 1;


                  triangles.at(i)->vertex[1].z =   coordinatesWorldToCamera[2][0] * triangles.at(i)->vertex[1].x +
                                                   coordinatesWorldToCamera[2][1] * triangles.at(i)->vertex[1].y +
                                                   coordinatesWorldToCamera[2][2] * triangles.at(i)->vertex[1].z +
                                                   coordinatesWorldToCamera[2][3] * 1;

                  //----------vertex[2] of this triangle------------
                  triangles.at(i)->vertex[2].x =   coordinatesWorldToCamera[0][0] * triangles.at(i)->vertex[2].x +
                                                   coordinatesWorldToCamera[0][1] * triangles.at(i)->vertex[2].y +
                                                   coordinatesWorldToCamera[0][2] * triangles.at(i)->vertex[2].z +
                                                   coordinatesWorldToCamera[0][3] * 1;


                  triangles.at(i)->vertex[2].y =    coordinatesWorldToCamera[1][0] * triangles.at(i)->vertex[2].x +
                                                    coordinatesWorldToCamera[1][1] * triangles.at(i)->vertex[2].y +
                                                    coordinatesWorldToCamera[1][2] * triangles.at(i)->vertex[2].z +
                                                    coordinatesWorldToCamera[1][3] * 1;


                  triangles.at(i)->vertex[2].z =   coordinatesWorldToCamera[2][0] * triangles.at(i)->vertex[2].x +
                                                   coordinatesWorldToCamera[2][1] * triangles.at(i)->vertex[2].y +
                                                   coordinatesWorldToCamera[2][2] * triangles.at(i)->vertex[2].z +
                                                   coordinatesWorldToCamera[2][3] * 1;

                  std::cout<<"after transformation\n";
                  triangles.at(i)->printVertexes();
            }
     }

}

void Camera::transformVertexesFromCoordinatesCameraToWorld(std::vector<Object*> scene_objects){

    for(int index = 0; index < scene_objects.size(); index++){

        std::vector<Triangle*> triangles = scene_objects.at(index)->triangles;
        for (int i = 0 ; i < triangles.size() ; i++){
                std::cout<<"\nTriangle["<<i<<"]\n";
                std::cout<<"before transformation\n";
                triangles.at(i)->printVertexes();

                //----------vertex[0] of this triangle------------

                 triangles.at(i)->vertex[0].x =   coordinatesCameraToWorld[0][0] * triangles.at(i)->vertex[0].x +
                                                  coordinatesCameraToWorld[0][1] * triangles.at(i)->vertex[0].y +
                                                  coordinatesCameraToWorld[0][2] * triangles.at(i)->vertex[0].z +
                                                  coordinatesCameraToWorld[0][3] * 1;


                 triangles.at(i)->vertex[0].y =    coordinatesCameraToWorld[1][0] * triangles.at(i)->vertex[0].x +
                                                   coordinatesCameraToWorld[1][1] * triangles.at(i)->vertex[0].y +
                                                   coordinatesCameraToWorld[1][2] * triangles.at(i)->vertex[0].z +
                                                   coordinatesCameraToWorld[1][3] * 1;


                 triangles.at(i)->vertex[0].z =   coordinatesCameraToWorld[2][0] * triangles.at(i)->vertex[0].x +
                                                  coordinatesCameraToWorld[2][1] * triangles.at(i)->vertex[0].y +
                                                  coordinatesCameraToWorld[2][2] * triangles.at(i)->vertex[0].z +
                                                  coordinatesCameraToWorld[2][3] * 1;



                 //----------vertex[1] of this triangle------------
                 triangles.at(i)->vertex[1].x =   coordinatesCameraToWorld[0][0] * triangles.at(i)->vertex[1].x +
                                                  coordinatesCameraToWorld[0][1] * triangles.at(i)->vertex[1].y +
                                                  coordinatesCameraToWorld[0][2] * triangles.at(i)->vertex[1].z +
                                                  coordinatesCameraToWorld[0][3] * 1;


                 triangles.at(i)->vertex[1].y =    coordinatesCameraToWorld[1][0] * triangles.at(i)->vertex[1].x +
                                                   coordinatesCameraToWorld[1][1] * triangles.at(i)->vertex[1].y +
                                                   coordinatesCameraToWorld[1][2] * triangles.at(i)->vertex[1].z +
                                                   coordinatesCameraToWorld[1][3] * 1;


                 triangles.at(i)->vertex[1].z =   coordinatesCameraToWorld[2][0] * triangles.at(i)->vertex[1].x +
                                                  coordinatesCameraToWorld[2][1] * triangles.at(i)->vertex[1].y +
                                                  coordinatesCameraToWorld[2][2] * triangles.at(i)->vertex[1].z +
                                                  coordinatesCameraToWorld[2][3] * 1;

                 //----------vertex[2] of this triangle------------
                 triangles.at(i)->vertex[2].x =   coordinatesCameraToWorld[0][0] * triangles.at(i)->vertex[2].x +
                                                  coordinatesCameraToWorld[0][1] * triangles.at(i)->vertex[2].y +
                                                  coordinatesCameraToWorld[0][2] * triangles.at(i)->vertex[2].z +
                                                  coordinatesCameraToWorld[0][3] * 1;


                 triangles.at(i)->vertex[2].y =    coordinatesCameraToWorld[1][0] * triangles.at(i)->vertex[2].x +
                                                   coordinatesCameraToWorld[1][1] * triangles.at(i)->vertex[2].y +
                                                   coordinatesCameraToWorld[1][2] * triangles.at(i)->vertex[2].z +
                                                   coordinatesCameraToWorld[1][3] * 1;


                 triangles.at(i)->vertex[2].z =   coordinatesCameraToWorld[2][0] * triangles.at(i)->vertex[2].x +
                                                  coordinatesCameraToWorld[2][1] * triangles.at(i)->vertex[2].y +
                                                  coordinatesCameraToWorld[2][2] * triangles.at(i)->vertex[2].z +
                                                  coordinatesCameraToWorld[2][3] * 1;

                 std::cout<<"after transformation\n";
                 triangles.at(i)->printVertexes();
           }
    }
}


void printMatrixWorldToCamera(){


}

void printMatrixCameraToWorld(){

}

/*
void Camera::transformVertexesFromCoordinatesWorldToCamera2(){
    //this method is for a single triangule.
    // Vertex 0 //

    scene.triangle.vertex[0].x = coordinatesWorldToCamera[0][0] * scene.triangle.vertex[0].x +
                                 coordinatesWorldToCamera[0][1] * scene.triangle.vertex[0].y +
                                 coordinatesWorldToCamera[0][2] * scene.triangle.vertex[0].z +
                                 coordinatesWorldToCamera[0][3] * 1;


    scene.triangle.vertex[0].y = coordinatesWorldToCamera[1][0] * scene.triangle.vertex[0].x +
                                 coordinatesWorldToCamera[1][1] * scene.triangle.vertex[0].y +
                                 coordinatesWorldToCamera[1][2] * scene.triangle.vertex[0].z +
                                 coordinatesWorldToCamera[1][3] * 1;


    scene.triangle.vertex[0].z = coordinatesWorldToCamera[2][0] * scene.triangle.vertex[0].x +
                                 coordinatesWorldToCamera[2][1] * scene.triangle.vertex[0].y +
                                 coordinatesWorldToCamera[2][2] * scene.triangle.vertex[0].z +
                                 coordinatesWorldToCamera[2][3] * 1;

    // Vertex 1 //

    scene.triangle.vertex[1].x = coordinatesWorldToCamera[0][0] * scene.triangle.vertex[1].x +
                                 coordinatesWorldToCamera[0][1] * scene.triangle.vertex[1].y +
                                 coordinatesWorldToCamera[0][2] * scene.triangle.vertex[1].z +
                                 coordinatesWorldToCamera[0][3] * 1;


    scene.triangle.vertex[1].y = coordinatesWorldToCamera[1][0] * scene.triangle.vertex[1].x +
                                 coordinatesWorldToCamera[1][1] * scene.triangle.vertex[1].y +
                                 coordinatesWorldToCamera[1][2] * scene.triangle.vertex[1].z +
                                 coordinatesWorldToCamera[1][3] * 1;


    scene.triangle.vertex[1].z = coordinatesWorldToCamera[2][0] * scene.triangle.vertex[1].x +
                                 coordinatesWorldToCamera[2][1] * scene.triangle.vertex[1].y +
                                 coordinatesWorldToCamera[2][2] * scene.triangle.vertex[1].z +
                                 coordinatesWorldToCamera[2][3] * 1;



    // Vertex 2 //

    scene.triangle.vertex[2].x = coordinatesWorldToCamera[0][0] * scene.triangle.vertex[2].x +
                                 coordinatesWorldToCamera[0][1] * scene.triangle.vertex[2].y +
                                 coordinatesWorldToCamera[0][2] * scene.triangle.vertex[2].z +
                                 coordinatesWorldToCamera[0][3] * 1;


    scene.triangle.vertex[2].y = coordinatesWorldToCamera[1][0] * scene.triangle.vertex[2].x +
                                 coordinatesWorldToCamera[1][1] * scene.triangle.vertex[2].y +
                                 coordinatesWorldToCamera[1][2] * scene.triangle.vertex[2].z +
                                 coordinatesWorldToCamera[1][3] * 1;


    scene.triangle.vertex[2].z = coordinatesWorldToCamera[2][0] * scene.triangle.vertex[2].x +
                                 coordinatesWorldToCamera[2][1] * scene.triangle.vertex[2].y +
                                 coordinatesWorldToCamera[2][2] * scene.triangle.vertex[2].z +
                                 coordinatesWorldToCamera[2][3] * 1;

}
*/





