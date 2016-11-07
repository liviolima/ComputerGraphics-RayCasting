#include "camera.h"

Camera::Camera()
{

    //deve possuir as posicoes do observador.
    //Para onde ele esta olhando
    camera_xyz_position[0] = 5;
    camera_xyz_position[1] = 5;
    camera_xyz_position[2] = 5;

    look_at_xyz_position[0] = 10;
    look_at_xyz_position[1] = 10;
    look_at_xyz_position[2] = 10;


}
