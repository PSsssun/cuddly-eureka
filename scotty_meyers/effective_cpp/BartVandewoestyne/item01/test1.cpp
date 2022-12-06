#include "name.h"
#include <iostream>

int main()
{
    authorName = "M";// avoid by using const char* const
    std::cout << *authorName << std::endl;
}