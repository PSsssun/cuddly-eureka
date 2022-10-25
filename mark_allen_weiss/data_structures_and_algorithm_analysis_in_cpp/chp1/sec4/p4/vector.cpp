#include <iostream>
#include <vector>

int main()
{

    std::cout << "1.4.4 vector and string: " << std::endl;
    std::vector<int> squares( 100 );

    for(int i = 0; i < squares.size(); ++i)
        squares[i] = i * i;

    for(int i = 0; i < squares.size(); ++i)
        std::cout << i << " " << squares[i] << std::endl;


    {
        std::vector<int> daysInMonth1 {12};//size 1 with element 1
        std::vector<int> daysInMonth2(12); //size 12 Must use () to call constructor that takes size
        std::cout << "daysInMonth1's size is :" << daysInMonth1.size() << std::endl;
        std::cout << "daysInMonth2's size is :" << daysInMonth2.size() << std::endl;
    
    }

    {
        int sum = 0;
        for (int i = 0; i < squares.size(); ++i)
            sum += squares[i];
        std::cout << "sum of elements of squares: " << std::endl;
    }

    {
        int sum = 0;
        for(int x : squares)
            sum += x;
        std::cout << "sum of elements of squares based on range for syntax: " << std::endl;
    }

    {
        int sum = 0;
        for(auto x : squares)
            sum += x;
        std::cout << "sum of elements of squares based on range-for syntax and auto type-declaration" << std::endl;
    }


    return 0;

}
