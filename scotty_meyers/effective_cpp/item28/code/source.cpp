#include<iostream>
#include<memory>
class Point {
public:
    Point(int x, int y):x_(x),y_(y){}
    void setX(int newVal);
    void setY(int newVal);
private:
    int x_,  y_;
};


void Point::setX(int newVal){
    x_ = newVal;
}

void Point::setY(int newVal){
    y_ = newVal;
}


struct RectData {
    Point ulhc;
    Point lrhc;
};

class Rectangle {
public:
    const Point& upperLeft() const {return pData->ulhc;}
    const Point& lowerRight() const {return pData->lrhc;}
private:
    std::shared_ptr<RectData> pData;
};

class GUIObject {
public:
    GUIObject(){}
    ~GUIObject(){}
};

const Rectangle boundingBox(const GUIObject& obj) {
    return Rectangle();
}

int main() {
    std::cout << "Item 28: Avoid returning handles to object internals." << std::endl;

    {
        GUIObject* pgo = new GUIObject();
        const Point* pUpperLeft = &(boundingBox(*pgo).upperLeft());
        printf("%p", pUpperLeft); // interesting!
    }

    return 0;

}

