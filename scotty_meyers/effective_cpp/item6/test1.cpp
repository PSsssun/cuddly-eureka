#include <iostream>


class HomeForSale {};


int main()
{
    HomeForSale h1;
    HomeForSale h2;
    HomeForSale h3(h1);
    h1 = h2;

    return 0;

}
