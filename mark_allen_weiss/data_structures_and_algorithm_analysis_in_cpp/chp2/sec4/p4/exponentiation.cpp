#include <iostream>

long long pow(long long x, int n){
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return pow(x * x, n / 2);
    else
        return pow(x, n - 1) * x;

}


int main(){
    std::cout << "efficient exponenetiation" << std::endl;

    std::cout << "pow(2, 10) is " <<  pow(2, 10) << std::endl;

}
