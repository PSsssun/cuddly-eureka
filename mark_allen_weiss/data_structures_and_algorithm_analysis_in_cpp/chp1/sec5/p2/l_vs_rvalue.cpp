#include <iostream>
#include <vector>
#include <string>
/*
   An lvalue is an expression that identifies a non-temporary object.
   An rvalue is an expression that identifies a temporary object or is a value (such
   as a literal constant) not associated with any object
   */

int main()
{
    std::cout << "Lvalues, Rvalues, and References" << std::endl;
    {
        std::vector<std::string> arr (3);
        const int x = 2;
        int y;

        int z = x + y;
        std::string str = "foo";
        std::vector<std::string> *ptr = &arr;
    }

    {
        std::cout << "lvalue reference" << std::endl;
        std::string str = "hell";
        std::string& rstr = str;
        rstr += '0';
        bool cond = (&str == &rstr);
        //std::string& bad1 = "hello";       //illegal: "hello" is not a modifiable lvalue 
        //std::string& bad2 = str + "";      //illegal: str+"" is not an lvalue 
        //std::string& sub = str.substr(0, 4); // illegal: str.substr(0, 4) is not an lvalue


    }

    {
        std::cout << "rvalue reference" << std::endl;
        std::string str = "hell";
        std::string&& bad1 = "hello";         //Legal
        std::string&& bad2 = str + "";        //Legal
        std::string&& sub = str.substr(0, 4); //Legal
        
    }

    {
        std::cout << "lvalue references use #1: aliasing complicated names " << std::endl;
        /*
           auto & whichList = theLists[ myhash( x, theLists.size() ) ];
           if( find(begin(whichList), end(whichList), x) != end(whichList))
             return false;
           whichList.push_back(x);
           */ 
    }

    {
        std::cout << "lvalue references use #2: range for loops" << std::endl;
        std::vector<int> arr(5);
        for (int i = 0; i < arr.size(); ++i)
            ++arr[i];
        
        std::cout << arr[0] << " " << arr[1] << " ... " << arr[4] << std::endl;
        for (auto x : arr) // broken it's a copy of arr
            ++x;

        std::cout << arr[0] << " " << arr[1] << " ... " << arr[4] << std::endl;
        for (auto & x : arr) //works
            ++x;
        std::cout << arr[0] << " " << arr[1] << " ... " << arr[4] << std::endl;
    }

    {
        std::cout << "lvalue reference use #3: avoiding a copy" << std::endl;

    
    }




}
