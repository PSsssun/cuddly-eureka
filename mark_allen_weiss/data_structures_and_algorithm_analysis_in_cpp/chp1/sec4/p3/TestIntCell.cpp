#include <iostream>
#include "IntCell.h"


int main()
{   
    {   
        std::cout << "Separation of Interface and implementation. " << std::endl;
        IntCell m;

        m.write( 5 );
        std::cout << "Cell contents: " << m.read() << std::endl;
    }


    {
        std::cout << "Objects Are Declared Like Primitive Types" << std::endl;
        // IntCell obj3 = 37; // constructor is explicit
        // IntCell obj4(); // function declaration
        IntCell obj1;
        IntCell obj2{ 12 };
        IntCell obj4{}; //zero parameter constructor
    
    }


    
    return 0;
}
