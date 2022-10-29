#include <iostream>
#include <vector>

/**
  * Performs the standard binary search using two comparisons per level
  * Returns index where item is found or -1 not found.
  */
template <typename Comparable>
int binarySearch(const std::vector<Comparable> & a, const Comparable & x){
    int low = 0, high = a.size() - 1;
    int NOT_FOUND = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (a[mid] < x)
            low = mid + 1;
        else if(a[mid] > x)
            high = mid -1;
        else
            return mid; // Found
    }

    return NOT_FOUND;

}


int main(){
    std::cout << "binary search method (for pre-sorted&preread list)" << std::endl;

    std::vector<int> testdata{-2, 1, 3, 5, 7, 8, 100};
    int to_be_searched = 5;
    std::cout << "index of " << to_be_searched << " is: " << binarySearch<int>(testdata, to_be_searched) << std::endl;

    return 0;

}
