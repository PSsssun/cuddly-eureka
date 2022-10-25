#include<iostream>

/**
  * A class for simulating an integer memory cell.
  */
class IntCell
{
public:
/**
  * Initiaization List
  * 1. save time in the case where the data members are class types that have complex initializations.
  * a. if a data member is const (meaning that is not changeable after the object has been constructed) 
  * b. if a data member it itself a class type that does not have a zero-parameter constructor
  *    then data member's value can only be initialized in the initialization list.
  */  
  explicit IntCell(int initialValue = 0)
        : storedValue{ initialValue } {}
    int read() const
    { return storedValue; }
    void write( int x )
    { storedValue = x; }

private:
    int storedValue;
};


int main()
{


    std::cout << "1.4.2 Extra Constructor Syntax and Accessors" << std::endl;
    {
        std::cout << "explicit Constructor " << std::endl;
        IntCell obj; //obj is an IntCell
        //obj = 37; //should not compile: type mismatch
        /**
          * The assignment statement should not work, because the right-hand side of the assignment operator is not another IntCell
          * C++ has lenient rules. Normally, a one-parameter constructor defines an implicit type conversion
          * into
          * IntCell tempoaray = 37;
          * obj = temporary;
          */
    }


    {
        std::cout << "Constant Member Function " << std::endl;
        std::cout << "mutator vs accessor" << std::endl;
    }

    return 0;
}
