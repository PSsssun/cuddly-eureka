#include <iostream>
#include <assert.h>

class Bird {
    // no fly function is declared
};

class FlyingBird : public Bird {
public:
    virtual void fly();
};



class Penguin: public Bird {
    // no fly function is declared
};


class Rectangle {
public:
    Rectangle() : height_(5), width_(4) {}
    virtual void setHeight(int newHeight) {};
    virtual void setWidth(int newWidth) {};
    virtual int height() const { return height_; }// return current values
    virtual int width() const { return width_; }

private:
    int height_;
    int width_;

};


void MakeBigger(Rectangle& r)
{
    int oldHeight = r.height();
    r.setWidth(r.width() + 10);
    assert(r.height() == oldHeight);

}


class Square : public Rectangle {
public:
    Square() : Rectangle() , height_(4), width_(4) {}
    virtual void setHeight(int newHeight);
    virtual void setWidth(int newWidth);
    virtual int height() const {return height_;}
    virtual int width() const {return width_;}
private:
    int height_;
    int width_;

};



void Square::setHeight(int newHeight) {
    height_ = newHeight;

}

void Square::setWidth(int newWidth) {
    width_ = newWidth;
}

int main() {
    std::cout << "Item 32: make sure public inheritance models is-a" << std::endl;

    Square s;
    assert(s.width() == s.height());
    MakeBigger(s);
    assert(s.width() == s.height());
    return 0;

}
