#include <iostream>
#include <vector>

/**
  * Recursive maximum contiguous subsequence sum algorithm.
  * Finds maximum sum in subarray spanning. a[left, right].
  * Does not attempt to maintain actual best sequence.
  */
int max3(int a, int b, int c);
int maxSumRec(const std::vector<int>& a, int left, int right) {
    if(left == right){ // Base Case
        if(a[left] > 0)
            return a[left];
        else
            return 0;
    }


    int center = (left+right) /2;
    int maxLeftSum = maxSumRec(a, left, center);
    int maxRightSum = maxSumRec(a, center+1, right);

    int maxLeftBorderSum = 0, leftBorderSum = 0;
    for(int i = center; i >= left; --i){
        leftBorderSum += a[i];
        if (leftBorderSum > maxLeftBorderSum)
            maxLeftBorderSum = leftBorderSum;
    }

    int maxRightBorderSum = 0, rightBorderSum = 0;
    for (int j = center+1; j <=right; ++j){
        rightBorderSum += a[j];
        if(rightBorderSum > maxRightBorderSum)
            maxRightBorderSum = rightBorderSum;
    }

    return max3(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);

}

/**
  * Driver for divide-and-conquer maximum contiguous
  * subsequence sum algorithm
  */
int maxSubSum3(const std::vector<int>& a) 
{
    return maxSumRec(a, 0, a.size()-1);
}

int max3(int a, int b, int c){
    int max = 0;
    max = a > b ?  a : b;
    max = max > c ? max : c;
    return max;
}


int main(){
    std::cout << "alogrithm3: O(n) = NlogN" << std::endl;
    std::vector<int> testdata{1, -1, 2, -2, 3, 0, 1, 0};

    std::cout << "maxsum: " << maxSubSum3(testdata) << std::endl;

    return 0;

}
