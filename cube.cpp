#include "cube.h"
#include "numbervector.h"

Cube::Cube()
{
    color.red = 255.0;
    color.green = 0.0;
    color.blue = 0.0;

    double x = 1;
    NumberVector v1 = NumberVector( x  , -x,  x);
    NumberVector v2 = NumberVector( x  , -x, -x);
    NumberVector v3 = NumberVector(-x  , -x, -x);
    NumberVector v4 = NumberVector(-x  , -x,  x);
    NumberVector v5 = NumberVector( x  ,  x,  x);
    NumberVector v6 = NumberVector( x  ,  x, -x);
    NumberVector v7 = NumberVector(-x  ,  x, -x);
    NumberVector v8 = NumberVector(-x  ,  x,  x);

    //triangles.resize(12);




    trianglesv[0] = Triangle(v4, v5, v8, redColor);
    trianglesv[1] = Triangle(v1, v4, v5, darkRedColor);
    trianglesv[2] = Triangle(v1, v2, v6, greenColor);
    trianglesv[3] = Triangle(v1, v5, v6, darkGreenColor);
    trianglesv[4] = Triangle(v5, v6, v8, blueColor);
    trianglesv[5] = Triangle(v6, v7, v8, darkBlueColor);

    trianglesv[6] = Triangle(v3, v4, v7, yellowColor);
    trianglesv[7] = Triangle(v4, v7, v8), darkYellowColor;
    trianglesv[8] = Triangle(v1, v3, v4, purpleColor);
    trianglesv[9] = Triangle(v2, v3, v6, darkPurpleColor);
    trianglesv[10] = Triangle(v2, v3, v6, cianColor);
    trianglesv[11] = Triangle(v3, v6, v1, darkCianColor);

    //scene_objects.push_back(dynamic_cast<Object*>(&cube));

    triangles.push_back(dynamic_cast<Triangle*>(&trianglesv[0]));
    triangles.push_back(dynamic_cast<Triangle*>(&trianglesv[1]));
    triangles.push_back(dynamic_cast<Triangle*>(&trianglesv[2]));
    triangles.push_back(dynamic_cast<Triangle*>(&trianglesv[3]));
    triangles.push_back(dynamic_cast<Triangle*>(&trianglesv[4]));
    triangles.push_back(dynamic_cast<Triangle*>(&trianglesv[5]));
    triangles.push_back(dynamic_cast<Triangle*>(&trianglesv[6]));
    triangles.push_back(dynamic_cast<Triangle*>(&trianglesv[7]));
    triangles.push_back(dynamic_cast<Triangle*>(&trianglesv[8]));
    triangles.push_back(dynamic_cast<Triangle*>(&trianglesv[9]));
    triangles.push_back(dynamic_cast<Triangle*>(&trianglesv[10]));
    triangles.push_back(dynamic_cast<Triangle*>(&trianglesv[11]));


}

Cube::Cube(double size, Color newColor)
{
    color.red = newColor.red;
    color.green = newColor.green;
    color.blue = newColor.blue;
    double x = size;
    NumberVector v1 = NumberVector( x  , -x,  x);
    NumberVector v2 = NumberVector( x  , -x, -x);
    NumberVector v3 = NumberVector(-x  , -x, -x);
    NumberVector v4 = NumberVector(-x  , -x,  x);
    NumberVector v5 = NumberVector( x  ,  x,  x);
    NumberVector v6 = NumberVector( x  ,  x, -x);
    NumberVector v7 = NumberVector(-x  ,  x, -x);
    NumberVector v8 = NumberVector(-x  ,  x,  x);

    //triangles.resize(12);

    trianglesv[0] = Triangle(v8, v5, v4, redColor);
    trianglesv[1] = Triangle(v1, v4, v5, darkRedColor);

    trianglesv[2] = Triangle(v6, v2, v1, greenColor);
    trianglesv[3] = Triangle(v1, v5, v6, darkGreenColor);

    trianglesv[4] = Triangle(v6, v5, v8, blueColor);
    trianglesv[5] = Triangle(v7, v6, v8, darkBlueColor);

    trianglesv[6] = Triangle(v3, v4, v7, yellowColor);
    trianglesv[7] = Triangle(v4, v7, v8), darkYellowColor;

    trianglesv[8] = Triangle(v3, v1, v4, purpleColor);
    trianglesv[9] = Triangle(v6, v3, v2, darkPurpleColor);

    trianglesv[10] = Triangle(v6, v3, v2, cianColor);
    trianglesv[11] = Triangle(v1, v6, v3, darkCianColor);


    //scene_objects.push_back(dynamic_cast<Object*>(&cube));

    triangles.push_back(dynamic_cast<Triangle*>(&trianglesv[0]));
    triangles.push_back(dynamic_cast<Triangle*>(&trianglesv[1]));
    triangles.push_back(dynamic_cast<Triangle*>(&trianglesv[2]));
    triangles.push_back(dynamic_cast<Triangle*>(&trianglesv[3]));
    triangles.push_back(dynamic_cast<Triangle*>(&trianglesv[4]));
    triangles.push_back(dynamic_cast<Triangle*>(&trianglesv[5]));
    triangles.push_back(dynamic_cast<Triangle*>(&trianglesv[6]));
    triangles.push_back(dynamic_cast<Triangle*>(&trianglesv[7]));
    triangles.push_back(dynamic_cast<Triangle*>(&trianglesv[8]));
    triangles.push_back(dynamic_cast<Triangle*>(&trianglesv[9]));
    triangles.push_back(dynamic_cast<Triangle*>(&trianglesv[10]));
    triangles.push_back(dynamic_cast<Triangle*>(&trianglesv[11]));








}



Color Cube::getColor(){
    return this->color;
}

void Cube::scale(double x, double y, double z){
    //qDebug() << "test-plane";
}

void Cube::translate(double x, double y, double z){
    //qDebug() << "test-plane";
}

double Cube::findIntersection(NumberVector origin, NumberVector direction){
    double x = 0.0;
    return x;
}
