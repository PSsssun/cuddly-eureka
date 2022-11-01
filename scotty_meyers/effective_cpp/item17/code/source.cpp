#include <iostream>
#include <memory>


class Widget {
public:
    Widget():priority_(new int) {}
    ~Widget() {}
    void SetPriority(const int n) {
        *priority_ = n;
    }
    int Priority() {
        return *priority_;
    }
    void ProcessWidget(std::shared_ptr<Widget> ptr, int priority);
private:
    int* priority_;
};

void Widget::ProcessWidget(std::shared_ptr<Widget> ptr, int priority) {
    if (ptr == NULL)
    {
        return;
    }
    else
    {
        ptr->SetPriority(priority);
    }
}

int main() {
    std::cout << "Item 17: Store newed objects in smart pointers in standalone statements." << std::endl;

    Widget bob;
    bob.ProcessWidget(std::shared_ptr<Widget>(new Widget), 10); // this call may leak resources

    std::shared_ptr<Widget> ptr(new Widget); //this call won't leak
    bob.ProcessWidget(ptr, 10);

    //bob.ProcessWidget(new Widget, 10);//No viable conversion from Widget* to std::shared_ptr<Widget>
    return 0;


}
