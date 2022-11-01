#include <iostream>
#include <vector>
/**
  * Return the maximum item in array a
  * Assumes a.size() > 0.
  * Comparable objects must provide operator < and operator =
  */
template <typename Comparable>
const Comparable & findMax(const std::vector<Comparable> & a)
{
    int maxIndex = 0;
    for(int i = 1; i < a.size(); ++i){
        if (a[maxIndex] < a[i])
            maxIndex = i;
    }
    return a[maxIndex];
}


int main(){
    
    std::cout << "function templates" << std::endl;
    std::vector<int> v1(37);
    std::vector<double> v2(40);
    for( auto & x: v1)
    {
        std::cout << x << " ";
    }
    std::vector<std::string> v3(80);
   // std::vector<IntCell> v4(75);
    
   std::cout << findMax(v1) << std::endl;
   std::cout << findMax(v2) << std::endl;
   std::cout << findMax(v3) << std::endl;
    
    return 0;
}
