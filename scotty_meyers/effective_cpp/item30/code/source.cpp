#include <iostream>

template<typename T>
inline const T& max(const T& a, const T& b) 
{
    return a < b ? b : a;
}


inline void f() {std::cout << "call f() " << std::endl;}


int main()
{
    std::cout << "Item 30: Understand the ins and outs of inlining." << std::endl;

    std::cout << max<double>(22.1, 100.10) << std::endl;

    void (*pf)() = f;

    pf(); // you are so strong.

    return 0;

}
