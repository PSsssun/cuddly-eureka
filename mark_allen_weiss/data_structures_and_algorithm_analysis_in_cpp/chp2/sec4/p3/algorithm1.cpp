#include <iostream>
#include <vector>

/**
  * Cubic maximum contiguous subsequence sum algorithm.
  */
int maxSubSum1(const std::vector<int>& a)
{
    int maxSum = 0;

    for(int i = 0; i < a.size(); ++i){
        for(int j = i; j < a.size(); ++j){
            int thisSum = 0;
            for(int k = i; k <= j; ++k){
                thisSum += a[k];
            }

            if(thisSum > maxSum){
                maxSum = thisSum;
            }
        }
    } 
    return maxSum;
}


int main(){

    std::cout << "algorithm 1: O(n) = N^3" << std::endl;
    std::vector<int> testdata = {1, -1, 2, -2, 3, 0, 0, 1};
    std::cout << maxSubSum1(testdata) << std::endl;

    return 0;
}
