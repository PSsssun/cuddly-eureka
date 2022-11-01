#include <iostream>

class Widget {
public:
    Widget(const std::string& str, const int n):str_(str), num_(n) { std::cout << "constructor called" << std::endl;}
    Widget operator=(const Widget &rhs)
    {
        this->num_ = rhs.num_;
        this->str_ = rhs.str_;
        return *this;
    }

    static void Print(const Widget &rhs) {
        std::cout << rhs.str_ << " " << rhs.num_ << std::endl;
    }
private:

    std::string str_;

    int num_;

};

int main()
{
    Widget w1("bob", 27);
    Widget w2("simon", 17);
    Widget::Print(w1);
    Widget::Print(w2);
    std::cout << "call non-ref assignment" << std::endl;
    w1 = w2;
    std::cout << "after assignment: " << std::endl;
    Widget::Print(w1);
    Widget w3("alex", 7);
    (w1 = w3) = w2;

    Widget::Print(w1);// print alex 7 not simon 17
    return 0;
}
