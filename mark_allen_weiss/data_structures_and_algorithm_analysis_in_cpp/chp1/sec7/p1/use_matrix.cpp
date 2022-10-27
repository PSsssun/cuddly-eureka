#include <iostream>
#include "matrix.hpp"


int main()
{

    std::cout << "The Data Members, Constructors, and Basic Accessors" << std::endl;
    matrix::matrix<double> m1(3, 4);
   // matrix::matrix<double> m2{m1};
    matrix::matrix<double> m3{1,0};
   //  matrix::matrix<double> m4(std::move(m3));
    std::cout << "m3 (empty matrix): " << "numrows: " << m3.numrows() << "numcols: " << m3.numcols() << std::endl;
    std::cout <<  m1.numrows() << std::endl << m1.numcols() << std::endl;
    
}
