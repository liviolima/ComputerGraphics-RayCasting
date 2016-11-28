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

/*
void Camera::transformVertexesFromCoordinatesWorldToCamera(){
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


void Camera::transformVertexesFromCoordinatesWorldToCamera2(std::vector<Object*> scene_objects){

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




    double coordinatesWorldToCamera[4][4] = {
      {camera_right_direction_i.x, camera_right_direction_i.y, camera_right_direction_i.z, -Oc_i1},
      {camera_down_direction_j.x, camera_down_direction_j.y, camera_down_direction_j.z, -Oc_j1},
      {camera_look_direction_k.x, camera_look_direction_k.y, camera_look_direction_k.z, -Oc_k1},
      {0.0, 0.0, 0.0, 1.0}

    };


    for(int j = 0; j < 4; j++){
        qDebug() <<coordinatesWorldToCamera[j][0]<<" "<<coordinatesWorldToCamera[j][1]<<" "<<coordinatesWorldToCamera[j][2]<<" "<<coordinatesWorldToCamera[j][3];
        qDebug() <<"\n";
    }


}




