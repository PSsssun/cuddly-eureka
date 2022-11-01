#include <iostream>
#include <vector>

long long gcd(long long m, long long n){
    while(n != 0)
    {
        long long rem = m%n;
        m = n;
        n = rem;
    
    }

    return m;

}


int main()
{
    std::cout << "Euclid's Algorithm" << std::endl;
    int m = 1989;
    int n = 1590;

    std::cout << "gcd for " << m << " and " << n << " is " << gcd(m, n) << std::endl;

    return 0;

    

}



