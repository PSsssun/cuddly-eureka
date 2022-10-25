#include <iostream>
#include <vector>


class IntCell1 {
public:
    IntCell1() = default;
    IntCell1(int x) : storedValue(x)
    {std::cout << "one-parameter constructor called" << std::endl;}
    IntCell1(const IntCell1& rhs) {
        storedValue = rhs.storedValue;
        std::cout << "copy constructor called" << std::endl;
    }
    IntCell1(IntCell1&& rhs) {
        storedValue = rhs.storedValue;
        std::cout << "move constructor called" << std::endl;
    }
    IntCell1 & operator=(const IntCell1 & rhs){
        this->storedValue = rhs.storedValue;
        std::cout << "copy assignment " << std::endl;
        return *this;
    }
    IntCell1 & operator=(IntCell1 && rhs){
        this->storedValue = rhs.storedValue;
        std::cout << "move assignment" << std::endl;
        return *this;
    }

private:
    int storedValue;
};

void foo(IntCell1&& value)
{
    IntCell1 b(std::move(value));
}


class IntCell{
public:
    explicit IntCell(int initialValue = 0)
    {storedValue = new int{ initialValue};}

    int read() const
    { return *storedValue;}

    void write(int x)
    {
        *storedValue = x;
    }
private:
    int *storedValue;
};

class Improved_IntCell{
public:
    explicit Improved_IntCell(int initialValue = 0)
    {   
        std::cout << "explicit constructor improved" << std::endl;
        storedValue = new int{ initialValue};
        v1 = {initialValue};// why can not v1{initialValue} ?
    }

    ~Improved_IntCell()  //Destructor  
    { 
        std::cout << "destructor" << std::endl;
        delete storedValue;
    }

    Improved_IntCell(Improved_IntCell &&rhs) : storedValue(rhs.storedValue),
                                              v1{std::move(rhs.v1)}  // move constructor
    {
        std::cout << "move constructor " << std::endl;
        rhs.storedValue = nullptr;
    }

    Improved_IntCell(const Improved_IntCell& rhs)  // copy constructor
    {   
        std::cout << "copy constructor" << std::endl;
        storedValue = new int{ *rhs.storedValue};
        v1 = rhs.v1;
    }

    Improved_IntCell& operator=(Improved_IntCell && rhs) // move assignment
    {
        std::cout << "move assignment" << std::endl;
        std::swap(storedValue, rhs.storedValue);
        std::swap(v1, rhs.v1);
        //std::swap(*this, rhs); // lead to mutal non-terminating recursion
        // move constructor -> move assignment -> repeating
        return *this;
    }

    Improved_IntCell& operator=(const Improved_IntCell& rhs)//copy assignment
    {
        std::cout << "copy assignment " << std::endl;
        if (this != &rhs) {
            Improved_IntCell copy = rhs;
            std::swap(*this, copy);
        }
        return *this;
    }
    
    void read() const{
        if (storedValue == nullptr)
        {
            std::cout << "nullptr" << std::endl;
        } else {
        std::cout << *storedValue << std::endl;
    }
    }

private:
    int* storedValue;
    std::vector<int> v1;

};

int main(){

    std::cout << "the big five: destructor, copy constructor, move constructor, copy assignment operator=, move assignment operator =" << std::endl;
    {
        std::cout << "default IntCell" << std::endl;
        IntCell1 b(5);
        IntCell1 c(std::move(b));
        foo(IntCell1(5));
        IntCell1 d(b);
        b = IntCell1{};
    }

    {
        std::cout << "When the defaults do not work" << std::endl;
        IntCell a{ 2 };
        IntCell b = a;
        IntCell c;

        c = b;
        a.write( 4 );
        std::cout << a.read() << std::endl << b.read() << std::endl << c.read() << std::endl;


    }

    {
        Improved_IntCell x1(1);
        Improved_IntCell x2(2);
        Improved_IntCell x3(x1);
        Improved_IntCell x4(std::move(x2));
        x2.read();
        x1.read();
        x1 = std::move(x4);
        x1.read();
    }
}
