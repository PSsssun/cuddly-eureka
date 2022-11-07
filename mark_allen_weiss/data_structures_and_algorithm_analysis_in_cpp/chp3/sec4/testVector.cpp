#include "Vector.h"
#include <iostream>


int main()
{
    {
    std::cout << "test explicit constructor: " << std::endl;
    Vector<int> v1{};// use {} over ()
    //Vector<int> v2 = 12; // this should fail
    std::cout << "default size is " << v1.size() << std::endl;
    std::cout << "default capacity is " << v1.capacity() << std::endl;
    v1.resize(100);
    std::cout << "after resize to 100" << std::endl << "current size is " << v1.size() << std::endl;
    std::cout << "current capacity is " << v1.capacity() << std::endl;
    v1.reserve(200); // newcapacity: 200
    std::cout << "after reserve(200), " << "current size is " << v1.size() << " current capacity is " << v1.capacity()  << std::endl;
    v1.reserve(50);
    std::cout << "after reserve(50), " << "current size is " << v1.size() << " current capacity is " << v1.capacity() << std::endl;


    
    
    
    }



}
