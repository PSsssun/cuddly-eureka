#include <iostream>
#include <vector>

/**
  * Quadratic maximum contiguous subsequence sum algorithm.
  */
int maxSubSum2(const std::vector<int>& a)
{
    int maxSum = 0;

    for (int i = 0; i < a.size(); ++i){
        int thisSum = 0;
        for(int j = i; j < a.size(); ++j){
            thisSum += a[j];
            if (thisSum > maxSum)
                maxSum = thisSum;
        }
    
    }
    return maxSum;
}



int main(){
    std::cout << "algorithm2: O(n) = N^2" << std::endl;

    std::vector<int> testdata{1, -1, 2, -2, 3, 0, 0, 1};

    std::cout << "maxSum: " << maxSubSum2(testdata) << std::endl;

    return 0;
}


