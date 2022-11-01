#include <iostream>

/**
  * A class for simulating a memory cell.
  */
template <typename Object>
class MemoryCell{
public:
    explicit MemoryCell(const Object & initialValue = Object{}) // zero-parameter constructor of Object 
        : storedValue{ initialValue} {}       // copy constructor of Object 
    const Object & read() const
    { return storedValue;}
    void write(const Object& x)
    { storedValue = x;}               // copy assignment of Object 
private:
    Object storedValue;


};

int main(){
    std::cout << "class templates" << std::endl;
    MemoryCell<int> m1;
    MemoryCell<std::string> m2{"hello"};


    m1.write(37);
    auto&  m3 = m1.read();
    std::cout << typeid(m3).name() << std::endl;
   // m3 = 2;
    m2.write(m2.read() + "cpp");
    std::cout << m1.read() << std::endl << m2.read() << std::endl;

    return 0;

}


