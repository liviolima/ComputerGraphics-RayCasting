#include "camera.h"

Camera::Camera()
{

    //deve possuir as posicoes do observador.
    //Para onde ele esta olhando



}

Camera::Camera(NumberVector pos, NumberVector look_at, NumberVector up){
    this->camera_xyz_position = pos;
    this->look_at_xyz_position = look_at;
    this->up_xyz = up;

    this->camera_look_direction = NumberVector(
                this->look_at_xyz_position.x - this->camera_xyz_position.x,
                this->look_at_xyz_position.y - this->camera_xyz_position.y,
                this->look_at_xyz_position.z - this->camera_xyz_position.z)
            .normalize();
    this->camera_right_direction = camera_look_direction.cross_product(up_xyz).normalize();
    this->camera_down_direction = camera_right_direction.cross_product(camera_look_direction);




}
