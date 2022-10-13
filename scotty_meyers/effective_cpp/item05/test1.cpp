#include <iostream>


class Empty {};


int main()
{
    Empty e1; //default constructor & destructor
    Empty e2(e1);//copy constructor
    e2 = e1; //copy assigmment operator
    return 0;
    
}
