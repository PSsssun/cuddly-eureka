#include <iostream>

class HomeForSale {
public:
    HomeForSale() = default;
private:
    HomeForSale(const HomeForSale&);
    HomeForSale& operator=(const HomeForSale&);
};

int main()
{
    HomeForSale h1;
    HomeForSale h2;
    //HomeForSale h3(h1);
    //h2 = h1;

    return 0;
}
