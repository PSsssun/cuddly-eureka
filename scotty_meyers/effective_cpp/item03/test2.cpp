#include <vector>
#include <iostream>
#include <iterator>

int main()
{
    std::vector<int> vec;
    const std::vector<int>::iterator iter = vec.begin(); // aka: int * const 
    *iter = 10;
    //++iter;
    std::vector<int>::const_iterator cIter = vec.begin(); // aka: const int *
    //*cIter = 10;
    ++cIter;

    return 0;


}

