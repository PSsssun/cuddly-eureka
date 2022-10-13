#include <iostream>

class Widget {
public:
    Widget(const std::string &str, const int n): str_(str), num_(n) {}
    Widget &operator=(const Widget &rhs) //return type is a reference to
    {
        this->num_ = rhs.num_;  // the current class
        this->str_ = rhs.str_;
        return *this;
    }

    Widget &operator+=(const Widget &rhs)
    {
        return *this;
    }
    void Print(const Widget &rhs) {
        std::cout << rhs.str_ << " " << rhs.num_ << std::endl;
    }

private:
    std::string str_;
    int num_;
};

int main() {
    std::cout << "Item 10: Have assignment operators return a reference to *this."
        << std::endl;

    Widget widget1("bob", 27);
    widget1.Print(widget1);
    Widget widget2("simon", 17);
    widget2.Print(widget2);
    widget1 = widget2;
    std::cout << "assignment after: " << std::endl;
    widget1.Print(widget1);
    return 0;



}
