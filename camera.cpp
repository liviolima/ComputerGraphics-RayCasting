#include "camera.h"
#include <iostream>
#include <QDebug>
#include "triangle.h"
#include "scene.h"

Camera::Camera()
{

    //deve possuir as posicoes do observador.
    //Para onde ele esta olhando
    qDebug()  << "Console Mode123S.\n";
    std::cout << "Console Mode123.\n";


}

void Camera::transformVertexFromCoordinatesWorldToCamera(Scene scene){
//**** Vertex 0 ****//

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

//**** Vertex 1 ****//

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



//**** Vertex 2 ****//

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


Camera::Camera(NumberVector pos, NumberVector look_at, NumberVector up){
    this->camera_xyz_position = pos;
    this->look_at_xyz_position = look_at;
    this->up_xyz = up;

    // This might be the reverse (look_at minus the position)...
    /*
     * this->look_at_xyz_position.x - this->camera_xyz_position.x,
       this->look_at_xyz_position.y - this->camera_xyz_position.y,
       this->look_at_xyz_position.z - this->camera_xyz_position.z
     * */
    this->camera_look_direction_k = NumberVector(
                this->camera_xyz_position.x - this->look_at_xyz_position.x,
                this->camera_xyz_position.y - this->look_at_xyz_position.y,
                this->camera_xyz_position.z - this->look_at_xyz_position.z)
            .normalize();
    this->camera_right_direction_i = camera_look_direction_k.cross_product(up_xyz).normalize();
    this->camera_down_direction_j = camera_right_direction_i.cross_product(camera_look_direction_k);


    double Oc_i = camera_xyz_position.x*camera_right_direction_i.x + camera_xyz_position.y*camera_right_direction_i.y +
                  camera_xyz_position.z*camera_right_direction_i.z;

    double Oc_j = camera_xyz_position.x*camera_down_direction_j.x + camera_xyz_position.y*camera_down_direction_j.y +
                  camera_xyz_position.z*camera_down_direction_j.z;

    double Oc_k = camera_xyz_position.x*camera_look_direction_k.x + camera_xyz_position.y*camera_look_direction_k.y +
                  camera_xyz_position.z*camera_look_direction_k.z;



    double coordinatesWorldToCamera[4][4] = {
      {camera_right_direction_i.x, camera_right_direction_i.y, camera_right_direction_i.z, -Oc_i},
      {camera_down_direction_j.x, camera_down_direction_j.y, camera_down_direction_j.z, -Oc_j},
      {camera_look_direction_k.x, camera_look_direction_k.y, camera_look_direction_k.z, -Oc_k},
      {0.0, 0.0, 0.0, 1.0}

    };


    for(int j = 0; j < 4; j++){
        qDebug() <<coordinatesWorldToCamera[j][0]<<" "<<coordinatesWorldToCamera[j][1]<<" "<<coordinatesWorldToCamera[j][2]<<" "<<coordinatesWorldToCamera[j][3];
        qDebug() <<"\n";
    }


}




