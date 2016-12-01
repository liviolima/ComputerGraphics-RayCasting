#ifndef CUBE_H
#define CUBE_H
#include "numbervector.h"
#include "color.h"
#include "object.h"
#include "triangle.h"
#include "vector"

class Cube : public Object
{
public:
    Cube();
    Cube(double size, Color newColor);

    Triangle trianglesv[12];
    Color color;
    double size_x, size_y, size_z;

    void scale(double x, double y, double z);
    void translate(double x, double y, double z);
    virtual double findIntersection(NumberVector origin, NumberVector direction);
    virtual Color getColor();

    Color redColor = Color(255.0, 0.0, 0.0, 0);
    Color darkRedColor = Color(153.0, 0.0, 0.0, 0);

    Color greenColor = Color(0.0, 255.0, 0.0, 0);
    Color darkGreenColor = Color(0.0, 51.0, 0.0, 0);

    Color blueColor = Color(0.0, 0.0, 255.0, 0);
    Color darkBlueColor = Color(0.0, 0.0, 102.0, 0);

    Color yellowColor = Color(255.0, 255.0, 0.0, 0);
    Color darkYellowColor = Color(204.0, 204.0, 0.0, 0);

    Color purpleColor = Color(204.0, 0.0, 204.0, 0);
    Color darkPurpleColor = Color(102.0, 0.0, 102.0, 0);

    Color cianColor = Color(0.0, 204.0, 204.0, 0);
    Color darkCianColor = Color(51.0, 255.0, 255.0, 0.0);

};

#endif // CUBE_H
