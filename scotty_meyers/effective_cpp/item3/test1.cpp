#include <iostream>

int main()
{
char greeting[] = "Hello";
char* p1 = greeting; //non-const pointer, non-const data
const char* p2 = greeting; //non-const pointer, const data
char* const p3 = greeting; // const pointer, non-const data
const char* const p4 = greeting; // const pointer, const data

std::cout << *(p1+1) << std::endl;
//*p2 = 'x';
std::cout << *p2 << std::endl;
//p3++;
std::cout << *p3 << std::endl;
std::cout << *p4 << std::endl;

return 0;

}
