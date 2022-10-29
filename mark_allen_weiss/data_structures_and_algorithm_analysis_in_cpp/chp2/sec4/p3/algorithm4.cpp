#include <iostream>
#include <vector>



/**
  * Linear-time maximum contiguous subsequnce sum algorithm.
  */

int maxSubSum4(const std::vector<int> & a)
{
    int maxSum = 0, thisSum = 0;

    for(int j = 0; j < a.size(); ++j){
        thisSum += a[j];
        if(thisSum > maxSum)
            maxSum = thisSum;
        else if(thisSum < 0)
            thisSum = 0;
        
    }

    return maxSum;

}


int main(){
    std::cout << "algorithm4: O(n) = N" << std::endl;
    std::vector<int> testdata{1, -1, 2, -2, 3, 0, 0, 1}; 

    std::cout << "max sum: " << maxSubSum4(testdata) << std::endl;

    return 0;



}
