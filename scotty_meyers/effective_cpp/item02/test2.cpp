#include <iostream>

template<typename T>
void f(T a){
    std::cout << a << std::endl;
}

#define CALL_WITH_MAX(a, b) f((a) > (b) ? (a) : (b))

template<typename T>
inline void callWithMax(const T& a, const T& b)
{
    f(a > b ? a : b);
}

int main(){
    {
        int a=5, b=0;
        CALL_WITH_MAX(++a, b);
        CALL_WITH_MAX(++a, b+10);
    }
    {
        int a = 5, b=0;
        callWithMax(++a, b);
        callWithMax(++a, b+10);
    }

    return 0;
}
