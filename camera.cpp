#include "camera.h"
#include <iostream>
#include <QDebug>

Camera::Camera()
{

    //deve possuir as posicoes do observador.
    //Para onde ele esta olhando
    qDebug()  << "Console Mode123S.\n";
    std::cout << "Console Mode123.\n";


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
    this->camera_look_direction = NumberVector(
                this->camera_xyz_position.x - this->look_at_xyz_position.x,
                this->camera_xyz_position.y - this->look_at_xyz_position.y,
                this->camera_xyz_position.z - this->look_at_xyz_position.z)
            .normalize();
    this->camera_right_direction = camera_look_direction.cross_product(up_xyz).normalize();
    this->camera_down_direction = camera_right_direction.cross_product(camera_look_direction);


    double Oc_i = camera_xyz_position.x*camera_right_direction.x + camera_xyz_position.y*camera_right_direction.y +
                  camera_xyz_position.z*camera_right_direction.z;

    double Oc_j = camera_xyz_position.x*camera_down_direction.x + camera_xyz_position.y*camera_down_direction.y +
                  camera_xyz_position.z*camera_down_direction.z;

    double Oc_k = camera_xyz_position.x*camera_look_direction.x + camera_xyz_position.y*camera_look_direction.y +
                  camera_xyz_position.z*camera_look_direction.z;



    double coordinatesWorldToCamera[4][4] = {
      {camera_right_direction.x, camera_right_direction.y, camera_right_direction.z, -Oc_i},
      {camera_down_direction.x, camera_down_direction.y, camera_down_direction.z, -Oc_j},
      {camera_look_direction.x, camera_look_direction.y, camera_look_direction.z, -Oc_k},
      {0.0, 0.0, 0.0, 1.0}

    };


    for(int j = 0; j < 4; j++){
        qDebug() <<coordinatesWorldToCamera[j][0]<<" "<<coordinatesWorldToCamera[j][1]<<" "<<coordinatesWorldToCamera[j][2]<<" "<<coordinatesWorldToCamera[j][3];
        qDebug() <<"\n";

    }


}




