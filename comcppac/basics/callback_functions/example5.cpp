#include <iostream>
#include <cstdlib>
#include <climits>
#include <compare>
#include <array>
 
int main() {
    std::array<int, 8> a { -2, 99, 0, -743, INT_MAX, 2, INT_MIN, 4 };
 
    std::qsort(
        a.data(),
        a.size(),
        sizeof(decltype(a)::value_type),
        [](const void* x, const void* y) {
            const int arg1 = *static_cast<const int*>(x);
            const int arg2 = *static_cast<const int*>(y);
            const auto cmp = arg1 <= arg2;
            if (cmp == true) return -1;
            if (cmp == false) return 1;
            return 0;
        });
 
    for (int ai : a)
        std::cout << ai << ' ';
}