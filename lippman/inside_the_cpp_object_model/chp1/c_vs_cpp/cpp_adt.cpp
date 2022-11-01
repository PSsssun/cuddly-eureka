#include "iostream"

class Point3d
{
public:
    Point3d( float x = 0.0, float y = 0.0, float z= 0.0 )
        : _x(x), _y(y), _z(z) {}
    

    // to be improved with const
    float x() const {return _x;}
    float y() const {return _y;}
    float z() const  {return _z;}

    void x( float xval) {_x = xval;}
// ... etc ...
private:
    float _x;
    float _y;
    float _z;
};


inline std::ostream& operator<<(std::ostream &os, const Point3d& pt)
{
    os << "(" <<  pt.x() << ", "
        << pt.y() << ", " << pt.z() << " )";
    return os;
};


int main()
{
    Point3d p;
    p.x(2.0);
    std::cout << p << std::endl;
    return 0;
}




