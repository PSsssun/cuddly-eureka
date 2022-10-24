#include <iostream>
template<unsigned n>
struct Factorial {
    enum {value = n * Factorial<n-1>::value};
};

template<>
struct Factorial<0> {
    enum {value = 1};
};

int main()
{
    std::cout << "Item 48: Be awre of template metaprogamming.\n" << std::endl;

    std::cout << Factorial<10>::value << std::endl;

    return 0;
}
