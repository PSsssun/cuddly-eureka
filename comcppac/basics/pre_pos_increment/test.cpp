#include <vector>
#include <iostream>


int main()
{
    std::vector<double> a = {1, 2, 3, 4, 5};
    int count1 = 0;
    int count2 = 1;
    std::cout << "a[count1++]: " << a[count1++] << std::endl;  // print out 1
    std::cout << "a[++count2]: " << a[++count2] << std::endl; // print out 3
    std::cout << "count1: " << count1 << std::endl;        // print out 1
    std::cout << "count2: " << count2 << std::endl;        // print out 2
    return 0;

}
