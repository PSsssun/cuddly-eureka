#include <iostream>
#include <vector>
#include <strings.h>
#include <string>
#include <functional>
// Generic findmax, with a function object, C++ style
// Precondition: a.size() > 0.
template <typename Object, typename Comparator>
const Object & findMax(const std::vector<Object>& arr, Comparator isLessThan)
{
    int maxIndex = 0;

    for (int i = 1; i < arr.size(); ++i)
    {
        if(isLessThan(arr[maxIndex], arr[i]))
            maxIndex = i;
    }
    return arr[maxIndex];
}

//Generic findMax, using default ordering
template<typename Object>
const Object & findMax(const std::vector<Object> & arr)
{
    return findMax(arr, std::less<Object>{ });   //this uses less<>{} function in functional
}

class CaseInsensitiveCompare{
public:
    bool operator()(const std::string& lhs, const std::string & rhs) const
    {return strcasecmp(lhs.c_str(), rhs.c_str()) < 0;}
};


int main()
{

    std::cout << "function objects" << std::endl;
    std::vector<std::string> arr = {"ZEBRA", "alligator", "crocodile"};

    std::cout << findMax(arr, CaseInsensitiveCompare{}) << std::endl;
    std::cout << findMax(arr) << std::endl;
    return 0;
}
