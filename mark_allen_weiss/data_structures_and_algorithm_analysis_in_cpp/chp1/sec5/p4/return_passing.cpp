#include <iostream>
#include <string>
#include <vector>

class LargeType{
public:
    std::vector<int> a{1, 2, 3, 4};
    int read() {
        return a[0];
    }
};

LargeType randomItem1(const std::vector<LargeType>& arr)
{
    return arr[0];
}

const LargeType & randomItem2(const std::vector<LargeType> & arr)
{
    return arr[0];
}


std::vector<int> partialSum(const std::vector<int>& arr)
{
    std::vector<int> result(arr.size());

    result[0] = arr[0];
    for (int i = 1; i < arr.size(); ++i)
        result[i] = result[i-1] + arr[1];

    return result; // the move semantics can be called on result here instead of 
}

int main()
{
    std::cout << "return passing" << std::endl;
    std::vector<LargeType> vec(5);
    LargeType item1 = randomItem1(vec); //copy
    
    LargeType item2 = randomItem2(vec); //copy
    
    item2.a[0] = 4;
    
    const LargeType & item3 = randomItem2(vec); //no copy
    std::cout << item3.a[0] << std::endl;  

    {
        std::cout << "copy in old c++; move in c++11" << std::endl;

        std::vector<int> vec{1, 2, 3, 4};
        std::vector<int> sums = partialSum(vec);    //here because of the distinction between a temporary and non-temporary and l-r value reference.
        for (auto && x : sums)
            std::cout << x << " ";
        std::cout << std::endl;
    }
}
