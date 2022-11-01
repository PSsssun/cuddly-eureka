#include <iostream>
#include <string>
#include <vector>

double avarage(double a, double b)
{
    return (a + b)/2;
}

void swap1(double a, double b) //swaps a and b, wrong parameter types
{
    double temp = b;
    b = a;
    a = temp;
}

std::string randomItem1(std::vector<std::string> arr)    //not efficient
{
    return arr[0];

}

std::string randomItem2(const std::vector<std::string>& arr){
    return arr[0];
}

void swap2(double & a, double & b)   //correct parameter types 
{
    double temp = b;
    b = a;
    a = temp;

}

std::string randomItem(const std::vector<std::string>& arr){
    return arr[0];
}

std::string randomItem(std::vector<std::string> && arr){
    return arr[0];
}
int main()
{

    std::cout << "parameter passing" << std::endl;
    double x = 3, y = 4;
    std::cout << avarage(x, y) << std::endl;

    swap1(x, y);
    std::cout << "after calling swap1: " << "x is " << x << " y is " << y << std::endl;
    
    swap2(x, y);
    std::cout << "after calling swap2: " << "x is " << x << " y is " << y << std::endl;
    std::vector<std::string> arr{"hello", "cpp"};
    std::cout << "calling randomItem1: " << randomItem1(arr) << std::endl;

    std::cout << "calling randomItem2: " << randomItem2(arr) << std::endl;

    /*
       1.If the formal parameter should be able to change the value of the actual argument, then you must use call-by-reference.
       2.Otherwise, the value of the actual argument cannot be changed by the formal parameter. If the type is a primitive type, 
         use call-by-value. Otherwise, the type is a class type and is generally passed using call-by-constant-reference, unless
         it is an unusally small and easily copyable type (e.g., a type that stores two or fewer primitive types)
    */

    
    std::cout << "lvalue reference: " << std::endl;

    std::vector<std::string> v {"hello", "world"};
    std::cout << "invoke lvalue method " << randomItem(v) << std::endl; //invokes lvalue method
    std::cout << "invoke rvalue method " << randomItem({"hello", "world"}) << std::endl;
    
 
 
} 
    
    

