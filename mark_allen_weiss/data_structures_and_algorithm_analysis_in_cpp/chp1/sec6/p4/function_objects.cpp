#include <iostream>
#include <vector>
#include <strings.h>
#include <string>

// Generic findMax, with a function object, Version #1
// Precondition: a.size() > 0
template <typename Object, typename Comparator>
const Object & findMax(const std::vector<Object> & arr, Comparator cmp)
{
    int maxIndex = 0;

    for (int i = 1;i < arr.size(); ++i){
        if (cmp.isLessThan(arr[maxIndex], arr[i]))
            {
                maxIndex = i;
            }
    }

    return arr[maxIndex];
}

class CaseInsensitiveCompare{
public:
    bool isLessThan(const std::string & lhs, const std::string & rhs) const
    {return strcasecmp(lhs.c_str(), rhs.c_str()) < 0;}
};

int main()
{
    std::vector<std::string> arr = {"ZEBRA", "alligator", "crocodile"};
    std::cout << findMax(arr, CaseInsensitiveCompare{}) <<  std::endl;
    return 0;
}
