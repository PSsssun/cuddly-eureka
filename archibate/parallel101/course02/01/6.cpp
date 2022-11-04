#include <vector>
#include <iostream>
#include <algorithm>

int main(){
    std::vector v = {4, 3, 2, 1}; //this works in c++17

    int sum = 0;
    std::for_each(v.begin(), v.end(), [&](auto i) {
       sum += i;
    });

    std::cout << sum << std::endl;

    return 0;


}
