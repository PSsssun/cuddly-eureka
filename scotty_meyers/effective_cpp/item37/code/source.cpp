#include <iostream>
#define ShapeColor(DO) \
    DO(Red)            \
    DO(Green)          \
    DO(Blue)

#define MAKE_ENUM(VAR) VAR,
enum MetaSyntactivVariable { ShapeColor(MAKE_ENUM)};


#define MAKE_STRINGS(VAR) #VAR,
const char* const MetaSyntactivVariableNames[] = {ShapeColor(MAKE_STRINGS)};


class Shape {
public:
    enum ShapeColor {Red, Green, Blue};
    void draw(ShapeColor color = Red) const
    {
        do_draw(color);
    }

private:
    virtual void do_draw(
        ShapeColor color) const = 0;

};

class Rectangle: public Shape {
public:
    void draw(ShapeColor color = Green) const { do_draw(color);}
private:
    virtual void do_draw(
        ShapeColor color) const;

};


void Rectangle::do_draw(ShapeColor color) const {
    std::cout << "Call Rectangle draw()"
            << "color is " << MetaSyntactivVariableNames[color] << std::endl;

}

int main(){
    std::cout << "Item 37: Never redefine a function inherited default parameter value.\n";
    

    {
        Shape* ps;
        Shape* pr = new Rectangle;
        pr->draw(Shape::Green);
        pr->draw();    
    }

    return 0;


}





