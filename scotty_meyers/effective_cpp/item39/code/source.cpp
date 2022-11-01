#include <iostream>

class Person {
public:
    void eat() const {std::cout << "Call Person::eat()\n";}

private:
    void f() {}
};


class Student : private Person {
public:
    void study() const {
        std::cout << "Call Person::study()\n";
        Person p;
        p.eat();
    }

};


void eat(const Person& p) {
    p.eat();

}

//void study(const Student& s) {
//    s.study();
//    Person p;
//    p.eat();
//}


class Timer {
public:
    explicit Timer(int tickFrequency) : frequency_(tickFrequency) {}
    virtual void OnTick() const;

private:
    int frequency_;

};

void Timer::OnTick() const {
    std::cout << "Call Timer::OnTick()\n";

}


class Widget : private Timer {
public:
    Widget(int tick): Timer(tick) {}
    void Tick() { OnTick();}
private:
    virtual void OnTick() const;

};

void Widget::OnTick() const {
    std::cout << "Widget::OnTick()\n";
}


class Empty {

};

class HoldsAnInt : private Empty {
private:
    char x;
    Empty e;

};

int main() {
    std::cout << "Item 39: Use private inheritance judiciously.\n";

    Person p;
    Student s;
    //eat(p);

    //eat(s);
    s.study();
    Widget w(100);
    w.Tick();

    std::cout << "HoldsAnInt size: " << sizeof(HoldsAnInt) << std::endl;


    return 0;

}
