#include <iostream>
#include <utility>

struct Bitmap {
public:
    /*Bitmap(const int n, const std::string& s) {
        this->num = n;
        this->str = s;
      }
       */
    int num;
    std::string str;
};


class Widget {
public:
    Widget(const Bitmap& bitmap) : bitmap_(const_cast<Bitmap*>(&bitmap)){};
    Widget &operator=(const Widget &rhs) {
        /* if (this == &rhs)
           {
            return *this;
           }
           */
        /* Bitmap *orig = bitmap_;

           bitmap_ = new Bitmap(*rhs.bitmap_);
           delete orig;
           */
        Widget temp(rhs);
        Swap(temp);
        return *this;
    }

    /*
       Widget &operator=(Widget rhs)
       {
        Swap(rhs);
        return *this;
       }
       */
    void Swap(Widget &rhs)
    {
        Bitmap *orig = new Bitmap();
        orig->num = rhs.bitmap_->num;
        orig->str = rhs.bitmap_->str;
        this->bitmap_ = orig;

    }
private:
    Bitmap *bitmap_;
};




int main()
{
    std::cout << "Item 11: Handle assignment to self in operator =." << std::endl;
    Bitmap *b = new Bitmap();
    b->num = 1;
    b->str = "Bob";
    Widget wid(*b);

    Bitmap *a = new Bitmap();
    a->num = 1;
    a->str = "Simon";
    Widget wid2(*a);

    wid = wid;

    const Bitmap *c = new Bitmap();
    Widget cwid(*c);

    return 0;
}
