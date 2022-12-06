// This macro has many drawbacks!
// #define max(a,b) ((a) > (b) ? (a) : (b))

// Better use an inline function (which isn't quite the same as the macro,
// because this version of max can only be called with ints)
//inline int max(int a, int b) { return a > b ? a : b; }

// But a template fixes that problem quite nicely:
#include <iostream>
template<class T>
inline const T& max(const T& a, const T& b)
{ 
    //std::cout << "a: " << a << " b: " << b << std::endl;
    return a > b ? a : b; 
}

int main()
{
  int a = 5, b = 0;
  max(++a, b);     // if use #define a is incremented twice -> (++a) > (b) ? (a) : (b) -> 
  std::cout << "a: " << a << " b: " << b << std::endl;
  max(++a, b+10);  // if use #define a is incremented once
  std::cout << "a: " << a << " b: " << b << std::endl;
}


