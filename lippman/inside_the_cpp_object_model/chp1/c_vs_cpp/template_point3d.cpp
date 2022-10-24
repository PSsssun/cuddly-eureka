#include <iostream>

template<class type>
class Point3d
{
public:
    Point3d(type x = 0.0, type y = 0.0, type z = 0.0)
        : _x(x), _y(y), _z(z) {}
    type x() {return _x;}
    void x(type xval) {_x = xval;}

private:
    type _x;
    type _y;
    type _z;
};


int main()
{
    Point3d<double> p1(0.0, 1.0, 2.0);
    Point3d<int> p2{1, 2, 3};
    std::cout << "double : " << typeid(p1.x()).name() << std::endl;
    std::cout << "int: " << typeid(p2.x()).name() << std::endl;
    return 0;

}
