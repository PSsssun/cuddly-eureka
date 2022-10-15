#include <iostream>
#include <vector>

namespace WidgetStuff {

//templatized WidgetImpl, etc.

template <typename T>
class WidgetImpl {
    public:
        WidgetImpl(T a, T b, T c, const std::vector<std::string>& v)
            : a_(a), b_(b), c_(c), v_(std::move(v)) {}
        ~WidgetImpl() {}
        T get_a() const {return a_;}
        T get_b() const {return b_;}
        T get_c() const {return c_;}

        std::vector<std::string> get_v() const {return v_;}

    private:
        T a_, b_, c_;
        std::vector<std::string> v_;
};


template <typename T> // as before, including the swap
class Widget {
    public:
        Widget(const std::string& name, const T& n, WidgetImpl<T>* p);
        ~Widget() {}
        Widget(const Widget& rhs);
        const Widget& operator=(const Widget& rhs);
        void swap(Widget& other);
        void print() {
            if (widget_ptr_ == nullptr) {
                std::cout << name_ << " love score is " << score_ << ", message is "
                          << "\"I love bob so much!\"" << std::endl;
               return; 
            }
            std::cout << name_ << "love score is " << score_ << ", message is \""
                      << widget_ptr_->get_a() << " " << widget_ptr_->get_b() << " "
                      << widget_ptr_->get_c() << "\"" << std::endl;
            std::cout << "I want to tell you: \"";
            std::string str;
            for (auto&& iter : widget_ptr_->get_v()) {
                str += iter + " ";
            }
            str.erase(str.end()-1);
            str += "\"";
            std::cout << str << std::endl;
        }
    private:
        std::string name_;
        T score_;
        WidgetImpl<T>* widget_ptr_;
};  // member function

template <typename T>
Widget<T>::Widget(const std::string& name, const T& n, WidgetImpl<T>* p)
    : name_(name), score_(n), widget_ptr_(p) {}

template <typename T>
Widget<T>::Widget(const Widget& rhs)
    : name_(std::move(rhs.name_)),
      score_(rhs.score_),
      widget_ptr_(rhs->widget_ptr_) {}

template <typename T>
const Widget<T>& Widget<T>::operator=(const Widget& rhs) {
    Widget& temp = const_cast<Widget&>(rhs);
    swap(temp);
    return *this;
}

template <typename T>   //non-member swap functions;
void swap(Widget<T>& a, //not part of the std namespace
          Widget<T>& b) {
    std::cout << "non-member swap function" << std::endl;
    a.swap(b);
}

template <typename T>
void Widget<T>::swap(Widget& other) {

    std::cout << "member swap" << std::endl;
    using std::swap;
    swap(widget_ptr_, other.widget_ptr_);
    std::cout << "stl swap" << std::endl;

}
}// namespace WidgetStuff

int main() {
    std::cout << "Item 25: Consider support for a non-throwing swap." << std::endl;

    std::vector<std::string> bob = {"I", "love", "bob", "too"};
    WidgetStuff::WidgetImpl<std::string>* bob_data = 
        new WidgetStuff::WidgetImpl<std::string>("I", "love", "you", bob);
    WidgetStuff::Widget<std::string> bobr("bob", "100", bob_data);


    std::vector<std::string> simon = {"I", "love", "simon", "too"};
    WidgetStuff::WidgetImpl<std::string>* simon_data =
        new WidgetStuff::WidgetImpl<std::string>("I", "love", "you", simon);
    WidgetStuff::Widget<std::string> simonr("simon", "100", simon_data);
    WidgetStuff::Widget<std::string> simonng("simon", "100", nullptr);
    simonng.print();
    std::cout << "love after" << std::endl;
    WidgetStuff::swap(simonr, bobr);
    bobr.print();
    return 0;

}
