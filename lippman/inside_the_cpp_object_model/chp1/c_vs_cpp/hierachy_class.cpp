#include <iostream>

class Point {
public:
    Point (float x = 0.0) : _x(x) {std::cout << "constructor of point" << std::endl;}
    float x() {return _x;}

    void x(float xval) {_x = xval;}
    //...
protected:
    float _x;

};


class Point2d : public Point{
public:
    Point2d(float x = 0.0, float y = 0.0)
        :Point(x), _y(y) {std::cout << "constructor of point2d" << std::endl;}
    float y() {return _y;}
    void y(float yval) {_y = yval;}
protected:
    float _y;

};

class Point3d: public Point2d{
public:
    Point3d(float x = 0.0, float y = 0.0, float z = 0.0)
        :Point2d(x, y), _z(z) {std::cout << "constructor of point3d" << std::endl;}
    float z() {return _z;}
    void z(float zval) {_z = zval;}
protected:
    float _z;
};


int main()
{
    Point3d p(1, 1, 1);

    return 0;

}
