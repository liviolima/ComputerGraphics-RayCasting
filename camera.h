#ifndef OBSERVER_H
#define OBSERVER_H


class Camera
{
    int camera_xyz_position[3];
    int look_at_xyz_position[3];

    struct ray{
        double Pi;
        double Pj;

    };

public:
    Camera();
};

#endif // CAMERA_H
