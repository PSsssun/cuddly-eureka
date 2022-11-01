#include <iostream>
#include <vector>

class Square{
public:
    explicit Square(double s= 0.0) : side{s}
    {}

    double getSide() const
    {return side;}

    double getArea() const
    {return side * side;}

    double getPerimeter() const
    {return 4 * side;}

    void print(std::ostream& out = std::cout ) const
    {out << "(square " << getSide() << ")";}

    bool operator< (const Square & rhs) const
    {return getSide() < rhs.getSide();}
private:
    double side;

};

template <typename Object>
const Object& findMax(const std::vector<Object>& v){
    int maxIndex = 0;
    for(int i = 1; i < v.size(); ++i)
    {
        if (v[maxIndex] < v[i])
        {
            maxIndex = i;
        }
    }
    return v[maxIndex];
    
}

//Define an output operator for Square
std::ostream& operator<<(std::ostream& out, const Square & rhs)
{
    rhs.print(out);
    return out;
}

int main()
{
    std::vector<Square> v = {Square{3.0}, Square{2.0}, Square{2.5}};
    std::cout << "Largest square: " << findMax(v) << std::endl;
    
    return 0;
}
